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

if(isset($_POST['nombre_usr'])||isset($_POST['clave_usr'])||isset($_POST['nombre_r_user'])||isset($_POST['telefono_usr'])||isset($_POST['direccion_usr'])) 
	{
		$consulta = "UPDATE usuarios SET nombre='".pg_escape_string ($_POST['nombre_usr'])."', clave='".pg_escape_string ($_POST['clave_usr']) ."', nombre_r='".pg_escape_string ($_POST['nombre_r_user'])."', telefono='".pg_escape_string ($_POST['telefono_usr'])."', direccion='".pg_escape_string ($_POST['direccion_usr'])."' WHERE num='".$_POST['num_usr']."'";	
		$result = pg_query($consulta) or die("Error query".pg_last_error() );
		?> <script language="javascript">
		alert("USUARIO MODIFICADO"); 
		</script>
		<?php					
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
			if(isset($_GET['num_usr']))
				{
				$consulta = "SELECT * FROM usuarios WHERE num='" . $_GET['num_usr']. "'";
				}
				else
					{
					$consulta = "SELECT * FROM usuarios WHERE num='" . $_POST['num_usr']. "'";	
					}
			$result = pg_query($consulta) or die("Error query".pg_last_error() );
			$row = pg_fetch_array($result, null, PGSQL_ASSOC);	
		?>			
	<!-- end #menu -->
	&nbsp;
	<div id="page">
	<form name = 'mod'  method = 'POST' action='usuario.php' onSubmit = 'return validar(this);'>
			<center><tr><td><font size="+1">Nombre Real:</font><br /> </td><td><input type='text' name='nombre_r_user' size=100 MAXLENGTH=100 value='<?php  echo  $row['nombre_r']?>' /></td></tr><br />
			<br />
			<tr>
				<td><font size="+1">Nombre Usuario:</font><input type='text' name='nombre_usr' MAXLENGTH=25 value='<?php  echo  $row['nombre']?>'/></td>
				&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
				<td><font size="+1">Clave:</font><input type='text' name='clave_usr' MAXLENGTH=20 value='<?php  echo  $row['clave']?>'/></td>
				&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
				<td><font size="+1">Permisos: <?php  echo  $row['permisos']?></font></td>
				&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
				<input type="hidden" name="permisos" value=<?php  echo  $row['permisos']?> />
				<td><font size="+1">Telefono:</font><input type='text' name='telefono_usr' MAXLENGTH=20 value='<?php  echo  $row['telefono']?>'/></td><br />
				<td><font size="+1">Direccion:</font><br /> </td><td><input type='text' name='direccion_usr' size=100 MAXLENGTH=200 value='<?php  echo  $row['direccion']?>' /></td>
				<input type="hidden" name="num_usr" value=<?php  echo  $row['num']?> />
			</tr>
			<br />		
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
