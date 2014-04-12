<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">

<?php 
$cadena = "host='localhost' dbname='b12011' user='b12011' password='baseuno' ";
$con = pg_connect($cadena) or die( "Error al conectar".pg_last_error() );	
session_start();?>

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta name="keywords" content="" />
<meta name="description" content="" />
<meta http-equiv="content-type" content="text/html; charset=utf-8" />
<title>Maná Impresores</title>
	<link rel="icon" type="image/gif" href='http://200.14.84.183/~17769837/images/whutgirl11.gif' />

<link href="http://fonts.googleapis.com/css?family=Abel|Arvo" rel="stylesheet" type="text/css" />
<link href="style.css" rel="stylesheet" type="text/css" media="screen" />
<script type="text/javascript" src="jquery-1.7.1.min.js"></script>
<script type="text/javascript" src="jquery.dropotron-1.0.js"></script>
</head>

<?php 
if(isset($_SESSION['nombre']))
			{ ?>
<body>
<div id="wrapper">
	<div id="header-wrapper">
		<div id="header">
			<center>
		<b><font size="+0"> <?php echo "Bienvenido <b>".$_SESSION["nombre"]."</b>,   "; ?></font></b>
		<b><font size="+0"> <?php echo " <a href=\"index.php?ac=logout\">Cerrar sesi&oacute;n</a>"; ?></font></b>
			</center>
			<div id="logo">
				<h1><a href="index.php">Maná Impresores</a></h1>
			</div>
		</div>
	</div>
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
			<li class="first" style="text-align:right"> <a href="carro.php"><span><font size="+2">Carro</font></span> </a></li>
			<li class="first" style="text-align:right"> <a href="factu.php"><span><font size="+2">Facturas</font></span> </a></li>
		</ul>
		<script type="text/javascript">
			$('#menu').dropotron();
		</script>
	</div>
	
	
	<!-- end #menu -->
	<div id="page">
	<form name = 'usuarios'  method = 'POST' action='inscar.php' onSubmit = 'return validar(this);'>
			<center>
			<TABLE border="1"> 
				<tr>
					<td><font size="+1">Nombre Producto:  </font><input type='text' size="50" name='nombre_pro' MAXLENGTH=60 /></td>
					<td><font size="+1">Cantidad:  </font><input type='text' name='cantidad_pro' MAXLENGTH=10 /></td>
					<td><font size="+1">Precio:   </font><input type='text' name='precio_pro' MAXLENGTH=10 /></td>
					<td><font size="+1">Codigo:   </font><input type='text' name='codigo_pro' MAXLENGTH=10 /></td>
					<br/>
				</tr>
			</TABLE>
			<br/>
			<tr>
				<font size="+1">Descripción:  </font>
				<br/>
				<textarea rows="1" cols="60" name="descripcion_car" style="color:#000000 ; font-size:12pt" MAXLENGTH=1000></textarea> 
				<br/>
			</tr>
			<br/>
        	<tr><td><input type="submit" style="width:100px; height:30px; font-size:12pt" value="Agregar"></td></tr>
			<tr><td><input type="reset" style="width:100px; height:30px; font-size:12pt" value="Limpiar"></td></tr> 
			</center>
	</form>

	</div>
	<!-- end #page -->
</div>
<div id="footer">
	<p>2012. Sitename.com. All rights reserved. Design by <a href="http://www.freecsstemplates.org/" rel="nofollow">FreeCSSTemplates.org</a>.</p>
</div>
<!-- end #footer -->

<?php

} else{ header("refresh:0; url=index.php");exit;} ?>

</body>
</html>

