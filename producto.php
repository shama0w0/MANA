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


<?			
$con_t = pg_connect($cadena) or die( "Error al conectar".pg_last_error() );	
$consulta_t = "SELECT * FROM config";	
$result_t = pg_query($consulta_t) or die("Error query".pg_last_error() );
$row_t = pg_fetch_array($result_t, null, PGSQL_ASSOC)
?>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta name="keywords" content="" />
<meta name="description" content="" />
<meta http-equiv="content-type" content="text/html; charset=utf-8" />
<title><?php  echo  $row_t['n_corto']?></title>
	<link rel="icon" type="image/gif" href='http://200.14.84.183/~17769837/images/whutgirl11.gif' />

<link href="http://fonts.googleapis.com/css?family=Abel|Arvo" rel="stylesheet" type="text/css" />
<link href="style.css" rel="stylesheet" type="text/css" media="screen" />
<script type="text/javascript" src="jquery-1.7.1.min.js"></script>
<script type="text/javascript" src="jquery.dropotron-1.0.js"></script>
</head>

<?

if(isset($_POST['nombre_pro'])&&isset($_POST['codigo_pro'])&&isset($_POST['cantidad_pro'])&&isset($_POST['precio_pro'])&&isset($_POST['cambio'])) 
	{
	if($_POST['cambio']==null||$_POST['cambio']==" "||$_POST['nombre_pro']==null||$_POST['nombre_pro']==" ")
			{
				?> 
					<script language="javascript">
					alert("EL NOMBRE O LA RAZON ESTAN VACIOS"); 
					</script>
				<?php
			}else
				{
			if(is_numeric($_POST['cantidad_pro'])&&is_numeric($_POST['precio_pro'])) 
					{
			
					if($_POST['descripcion_pro']==null||$_POST['descripcion_pro']==" ")
						{
						$consulta = "UPDATE productos SET nombre='" . pg_escape_string ($_POST['nombre_pro']) . "', cantidad='" . pg_escape_string ($_POST['cantidad_pro']) . "', precio='" . pg_escape_string ($_POST['precio_pro']) . "' WHERE codigo='" . $_POST['codigo_pro'] . "'";	
						$result = pg_query($consulta) or die("Error query".pg_last_error() );
						?> <script language="javascript">
						alert("PRODUCTO MODIFICADO"); 
						</script>
						<?php					
						}
						else
							{
							$consulta = "UPDATE productos SET nombre='" . pg_escape_string ($_POST['nombre_pro']) . "', cantidad='" . pg_escape_string ($_POST['cantidad_pro']) . "', precio='" . pg_escape_string ($_POST['precio_pro']) . "', descripcion='" . pg_escape_string ($_POST['descripcion_pro']) . "' WHERE codigo='" . $_POST['codigo_pro'] . "'";	
							$result = pg_query($consulta) or die("Error query".pg_last_error() );
							?> <script language="javascript">
							alert("PRODUCTO MODIFICADO"); 
							</script>
							<?php	
							}
							$fecha_hora=date("d-m-Y H:i:s");
							$consulta2 = "INSERT INTO logs (origen, nombre_user, razon, nombre_pro, codigo_pro, fecha) VALUES ('modificar_producto','" . $_SESSION["nombre"] . "','" . $_POST['cambio'] . "','" . $_POST['nombre_pro'] . "','" . $_POST['codigo_pro'] . "','" . $fecha_hora . "')";
							$result2 = pg_query($consulta2) or die("Error query".pg_last_error() );
					
					}
					else
						{
						?> 
							<script language="javascript">
							alert("CANTIDAD Y PRECIO DEBEN SER NUMEROS"); 
							</script>
						<?php
						}
				}
	}

?>

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
				<h1><a href="index.php"><?php  echo  $row_t['n_corto']?></a></h1>
			</div>		
		</div>
	</div>				
		<form action="carro.php" method="post" style="text-align:center">
			<input type=image src="images/carro3.png" width="50" height="50" >
		</form>
	<!-- end #header -->
	<div id="menu-wrapper">
		<ul id="menu">
			
			<li><span><font size="+2">Stock</font></span>
				<ul>
					<li class="first"> <a href="inspro.php"><font size="+1">Agregar Producto</font></a> </li>
					<li class="last"> <a href="mospro.php"><font size="+1">Listado Stock</font></a> </li>
				</ul>
			</li>
			<li class="first" style="text-align:right"> <a href="vender.php"><span><font size="+2">Vender</font></span> </a></li>
			<li class="first" style="text-align:right"> <a href="clientes.php"><span><font size="+2">Clientes</font></span> </a></li>
			<li class="first" style="text-align:right"> <a href="factu.php"><span><font size="+2">Facturas</font></span> </a></li>
			<?
			$consulta_aux = "SELECT * FROM usuarios WHERE nombre='" . $_SESSION["nombre"]. "'";	
			$result_aux = pg_query($consulta_aux) or die("Error query".pg_last_error() );
			$row_aux = pg_fetch_array($result_aux, null, PGSQL_ASSOC);
			if($row_aux['permisos']=="administrador")
				{
				?>
				<li class="first" style="float: right;"> <a href="moslog.php"><span><font size="+2">LOGS</font></span> </a></li>
				<?
				}
			?>

		</ul>
		<script type="text/javascript">
			$('#menu').dropotron();
		</script>
	</div>
		<?
			$con = pg_connect($cadena) or die( "Error al conectar".pg_last_error() );	
			if(isset($_GET['codigo_pro']))
				{
				$consulta = "SELECT * FROM productos WHERE codigo='" . $_GET['codigo_pro']. "'";
				}
				else
					{
					$consulta = "SELECT * FROM productos WHERE codigo='" . $_POST['codigo_pro']. "'";	
					}
			$result = pg_query($consulta) or die("Error query".pg_last_error() );
			$row = pg_fetch_array($result, null, PGSQL_ASSOC);	
		?>			
	<!-- end #menu -->
	<div id="page">
	 <center>Los campos marcados con un * son obligatorios. Ademas, si desea hacer un cambio en el producto debe especificar la razon del cambio.</center>
	 <br />
	<form name = 'mod'  method = 'POST' action='producto.php' onSubmit = 'return validar(this);'>
			<center><tr><td><font size="+1">*Nombre Producto:</font><br /> </td><td><input type='text' name='nombre_pro' size=100 MAXLENGTH=200 value='<?php  echo  $row['nombre']?>' /></td></tr><br />
			<br />
			<tr>
				<td><font size="+1">*Cantidad:</font><input type='text' name='cantidad_pro' MAXLENGTH=10 value='<?php  echo  $row['cantidad']?>'/></td>
				&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
				<td><font size="+1">*Precio:</font><input type='text' name='precio_pro' MAXLENGTH=10 value='<?php  echo  $row['precio']?>'/></td>
				&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
				<td><font size="+1">Codigo: <?php  echo  $row['codigo']?></td></font><br />
				<input type="hidden" name="codigo_pro" value=<?php  echo  $row['codigo']?> />
			</tr>
			<br />
			<tr>
				<td>
					<font size="+1">Descripción: </font> <br /><textarea rows="4" cols="80" name="descripcion_pro" MAXLENGTH=1000 ><?php  echo  $row['descripcion']?></textarea>
					</td>
				</tr>
			<br />
<tr><td><font size="+1">*Razon del Cambio: </font> <br /> <textarea rows="4" cols="60" name="cambio" MAXLENGTH=1000 ></textarea></td></tr><br />			
			<tr><td><input type="submit" value="Modificar"></td></tr>
			<tr><td><input type="reset" value="Reset"></td></tr>
			</center>
	</form>

	</div>
	<!-- end #page -->
</div>

<!-- end #footer -->
</body>
</html>

