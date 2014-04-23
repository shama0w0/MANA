<?php
$cadena = "host='localhost' dbname='b17769837_dsi' user='b17769837_shama' password='bdddoce' ";
$con = pg_connect($cadena) or die( "Error al conectar".pg_last_error() );	
session_start();

function login()
{	
if(!isset($_SESSION["nombre"]))
	{
		?>
		<form id="login" action="index.php?ac=login" method= "post" style="margin:0px;">
		<b><font color="black" size="+0">Usuario: </font></b><input type="text" name="nombre" size="15"/>
		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
		<b><font color="black" size="+0">Contraseña: </font> <input type="password" name="password" size="10"/>
		&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
		<input type="submit" value="INGRESAR"/>
		</form>

		
		<?php
	} 
	else{
		?><b><font color="black" size="+0"> <?php echo "Bienvenido <b>".$_SESSION["nombre"]."</b>,   "; ?></font></b>
		<b><font size="+0"> <?php echo " <a href=\"index.php?ac=logout\">Cerrar sesi&oacute;n</a>"; ?></font></b>
		<? 
		$cadena = "host='localhost' dbname='b17769837_dsi' user='b17769837_shama' password='bdddoce' ";
		$con = pg_connect($cadena) or die( "Error al conectar".pg_last_error() );
		$username = $_SESSION["nombre"];
		$query = pg_query($con,"SELECT * FROM usuarios WHERE nombre = '$username'") or die("Error consulta SQL");
		$datapermiso = pg_fetch_array($query);
		if($datapermiso['permisos'] == "administrador")
			{?>
			<form action="configadmin.php" method="post" style="text-align:center">
				<input type=image src="images/engrana.png" width="30" height="30" >
			</form>
			<?php
			}
		}
	if (isset($_GET['ac']))
	{
		switch($_GET['ac'])
			{
			case  "login":  
				if($_POST['nombre']!=NULL && $_POST['password']!=NULL)
					{
					$username=$_POST['nombre'];
					$password=$_POST['password'];
					$cadena = "host='localhost' dbname='b17769837_dsi' user='b17769837_shama' password='bdddoce' ";
					$con = pg_connect($cadena) or die( "Error al conectar".pg_last_error() );	
					$query = pg_query($con,"SELECT nombre,clave FROM usuarios WHERE nombre = '$username'") or die("Error consulta SQL");
					$data = pg_fetch_array($query);
					if($data['clave'] != $password || $data['nombre']!= $username) 
						{
						
						print "<script>alert('Login incorrecto. Revise que el usuario y la clave sean correctos.')</script>";
						header("refresh:1; url=index.php"); 
						}else{
							$query = pg_query("SELECT nombre,clave FROM usuarios WHERE nombre = '$username'") or die(pg_last_error());
							$row = pg_fetch_array($query);
							$_SESSION["s_username"] = $row['nombre'];                  	
							$_SESSION["nombre"] = $row['nombre'];
							print "<script>alert('Has ingresado correctamente ".$_SESSION['nombre'].".')</script>"; 
							header("refresh:0; url=index.php");
							exit;
							}

				}else{
					if($_POST['nombre']==NULL)
						{
						?> <script language="javascript">
				  		alert("DEBE INGRESAR UN NOMBRE DE USUARIO");
				  		</script>
				  		<?php
				  		header("refresh:1; url=index.php");
						}
					if($_POST['password']==NULL)
						{	
						?> <script language="javascript">
				  		alert("DEBE INGRESAR UNA CONTRASEÑA");
				  		</script>
				  		<?php
				  		header("refresh:1; url=index.php");
		 				}
					}
			case "logout":

				unset($_SESSION["nombre"]);
				session_destroy();
				header('refresh:0; url=index.php');

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
					while (strlen($nombrec) < 60)
                            {
                                    $nombrec= $nombrec.' ';
                            }
					//$m=trim($_POST['descripcion_car']);
					//$j=sprintf("%-10.1000s",$m);
					
					//$nombrec = trim($nombrec," ");
 
					$buffer = $_SESSION["id"]."TXIN 000580053elicar00".$nombrec;
					$salida = ' ';

					// ESCRIBIENDO EL BUFFER EN EL SOCKET
					socket_write($socket, $buffer);

					// LEYENDO RESPUESTA DEL SOCKET

    $salida = socket_read($socket,3000);

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

</body>
</html>

