<?php
session_start();

function login()
{	if(!isset($_SESSION["nombre"]))
	{
		?>
		<form id="login" action="index.php?ac=login" method= "post" style="margin:0px;">
		Usuario <input type="text" name="nombre" size="15"/>
		Password <input type="password" name="pass" size="10"/>
		<input type="submit" value="Login"/>
		</form>
		<?php
	}
	else{
		echo "Bienvenido, <b>".$_SESSION["nombre"]."</b>"   ;
		echo " <a href=\"index.php?ac=logout\">Cerrar sesi&oacute;n</a>";
		}
	if (isset($_GET['ac']))
	{
		switch($_GET['ac'])
		{
			case  "login":  
							$host = "localhost";
							$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
							$puerto = 3024;
							$buffer = "hola";
							$salida= ' ';
							socket_connect($socket, $host, $puerto);
							socket_write($socket,'hola');
							
						 	$_SESSION["id"] = socket_read($socket,2048);
							socket_close($socket);
						    $socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
							socket_connect($socket, $host, $puerto);

				    
						  	$nombre = $_POST['nombre'];
                            while (strlen($nombre) < 15)
                            {
                                    $nombre= $nombre.' ';
                            }
                            $clave= $_POST['pass'];
							$_SESSION["pass"]= $clave;
                            while (strlen($clave) < 10)
                            {
                                    $clave= $clave.' ';
                            }
                            $buffer = $_SESSION["id"]."TXIN 000580042logusu00".$nombre.$clave;
                            $salida= ' ';
                            socket_write($socket, $buffer);

							while($salida = socket_read($socket,3024))
							{							      
						        break;
							}
							socket_close($socket);

							if ($salida == 'OK! logusu0001')
							{
								$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
								$_SESSION["nombre"] = $nombre;
								socket_connect($socket, $host, $puerto);
							socket_close($socket);
						 	header('Location: index.php');
							}
							else
							{
								?> 
									<script language="javascript">
									alert("Usuario o clave incorrecta");
									</script>
								<?php
							}
							break;
			case "logout":

                            $host = "localhost";
                            $socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
                            $puerto = 3024;                          
                            $salida= ' ';
                            socket_connect($socket, $host, $puerto);
                            socket_write($socket,$_SESSION["id"].'chao');                          

                            socket_close($socket);

							unset($_SESSION["nombre"]);
							unset($_SESSION["pass"]);
							session_destroy();
						 	header('Location: index.php');
							break;

			default:		break;
		}
	}

}

?>



<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<?php
if(!isset($_SESSION["nombre"]))
{
header('Location: index.php');
}
?>

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta name="keywords" content="" />
<meta name="description" content="" />
<meta http-equiv="content-type" content="text/html; charset=utf-8" />
<title>The Outraged</title>
	<link rel="icon" type="image/gif" href='http://200.14.84.183/~17769837/images/whutgirl11.gif' />

<link href="http://fonts.googleapis.com/css?family=Abel|Arvo" rel="stylesheet" type="text/css" />
<link href="style.css" rel="stylesheet" type="text/css" media="screen" />
<script type="text/javascript" src="jquery-1.7.1.min.js"></script>
<script type="text/javascript" src="jquery.dropotron-1.0.js"></script>
</head>
<body>
<div id="wrapper">
	<div id="header-wrapper">
		<div id="header">
			<center>
					<?php
						login();
					?>
			</center>
			<div id="logo">
				<h1><a href="index.php">The Outraged</a></h1>
				<p>Proyecto Diseño de Sistemas Transaccionales</p>
			</div>
		</div>
	</div>
	<!-- end #header -->
	<div id="menu-wrapper">
		<ul id="menu">
			<li class="current_page_item"><a href="index.php"><span>Home</span></a></li>
			<li><span>Empleados</span>
				<ul>
					<li class="first"> <a href="insemp.php">Agregar Empleados</a> </li>

				</ul>
			</li>
			<li><span>Cargos</span>
				<ul>
					<li class="first"> <a href="inscar.php">Agregar Cargo</a> </li>
					<li class="last"> <a href="moscar.php">Mostrar Cargos</a> </li>

				</ul>
			</li>	
			<li class="first" style="text-align:right"> <a href="fondos.php"><span> Fondos</span> </a></li>
			 <h4 style="text-align:right">
			<form method="get" action="buscar.php">
							Buscador: <input type="text" name="n" id="search-text" value="" />
			</form>
 			</h4>
		</ul>
		<script type="text/javascript">
			$('#menu').dropotron();
		</script>
	</div>
	<?php
	# Ejecutando el ingreso

	//if($_POST['nombre_car']!=NULL && $_POST['descripcion_car']!=NULL)
	//	{

	
	
	
	
					// DEFINICIÓN DE VARIABLES
					$puerto = 3024;
					$host = "localhost";

					// CREANDO EL SOCKET: (IP PROTOCOL[IPV4], TYPE SOCKET[TCP], PROTOCOL[TCP])
					$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
					$conexion = socket_connect($socket, $host, $puerto);

					// CREAR PREGUNTA
					$nombrec = $_GET['n'];
					//while (strlen($nombrec) < 60)
                            //{
                                       // $nombrec= "multiple";
                            //}

					//$m=trim($_POST['descripcion_car']);
					//$j=sprintf("%-10.1000s",$m);
					

 
					$buffer = $_SESSION["id"]."TXIN 000580051buscar00".$nombrec;
					$salida = ' ';

					// ESCRIBIENDO EL BUFFER EN EL SOCKET
					socket_write($socket, $buffer);

					// LEYENDO RESPUESTA DEL SOCKET

    $salida = socket_read($socket,3000);
    $pieces = explode("/",$salida);
	$ix = 2;
	
    $pieces[$ix] = trim($pieces[$ix]," ");
    $pieces[$ix+1] = trim($pieces[$ix+1]," ");

					// CERRANDO LA CONEXIÓN
					//socket_close($socket);
					/*if ($salida == 'OK! inscar0001')
							{
								$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
								?> <script language="javascript">
								alert("SE HA AGREGADO EL CARGO EXITOSAMENTE");
								</script>
								<?php
							} 

					if ($salida == 'OK! inscar0002')
							{
								$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
								?> <script language="javascript">
								alert("YA EXISTE UN CARGO ESTE NOMBRE");
								</script>
								<?php
							} 
							
					if ($salida == 'OK! inscar0003')
							{
								$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
								?> <script language="javascript">
								alert("ERROR AL INSERTAR CARGO");
								</script>
								<?php
							} 
							*/
							
							
			
		
	/*}else
		{
		if($_POST['nombre_car']==NULL){
		?> <script language="javascript">
			  alert("DEBE INGRESAR UN NOMBRE AL CARGO");
			  </script>
			  <?php }
	    if($_POST['descripcion_car']==NULL){
		?> <script language="javascript">
			  alert("DEBE INGRESAR UNA DESCRIPCION");
			  </script>
			  <?php }
  
		}*/
//}
	

?> 
	
	<!-- end #menu -->
	<div id="page">

	<form name = 'usuarios'  method = 'POST' action='buscar.php' onSubmit = 'return validar(this);'>
			<center><tr><td>Nombre cargo: </td><td><input type='text' name='nombre_car' MAXLENGTH=60 value="<?php echo $pieces[$ix]; ?>" /></td></tr><br />
			<tr><td>Descripción:  <textarea rows="4" cols="60" name="descripcion_car" MAXLENGTH=1000 ><?php echo $pieces[$ix+1]; ?></textarea></td></tr><br />
        		<tr><td><input type="submit" value="Modificar"></td></tr>
			<tr><td><input type="reset" value="Limpiar"></td></tr>
			</center>
	</form>


	</div>
	<!-- end #page -->
</div>
<div id="footer">
	<p>2012. Sitename.com. All rights reserved. Design by <a href="http://www.freecsstemplates.org/" rel="nofollow">FreeCSSTemplates.org</a>.</p>
</div>
<!-- end #footer -->
</body>
</html>
