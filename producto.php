



<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">



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
<body>
<div id="wrapper">
	<div id="header-wrapper">
		<div id="header">
			<center>

			</center>
			<div id="logo">
				<h1><a href="index.php">Maná Impresores</a></h1>
			</div>
		</div>
	</div>
	<!-- end #header -->
	<div id="menu-wrapper">
		<ul id="menu">
			
			<li><span>Stock</span>
				<ul>
					<li class="first"> <a href="inspro.php">Agregar Producto</a> </li>
					<li class="last"> <a href="mospro.php">Listado Stock</a> </li>

				</ul>
			</li>
			
			<li class="first" style="text-align:right"> <a href="vender.php"><span> Vender</span> </a></li>
			<li class="first" style="text-align:right"> <a href="carro.php"><span> Carro</span> </a></li>
			<li class="first" style="text-align:right"> <a href="factu.php"><span> Facturas</span> </a></li>
					

		</ul>
		<script type="text/javascript">
			$('#menu').dropotron();
		</script>
	</div>
	
	
	<!-- end #menu -->
	<div id="page">
	<form name = 'usuarios'  method = 'POST' action='inscar.php' onSubmit = 'return validar(this);'>
			<center><tr><td>Nombre Producto:<br /> </td><td><input type='text' name='nombre_pro' MAXLENGTH=60 /></td></tr><br />
			<tr><td>Cantidad:<br /></td><td><input type='text' name='cantidad_pro' MAXLENGTH=10 /></td></tr><br />
			<tr><td>Precio:<br /></td><td><input type='text' name='precio_pro' MAXLENGTH=10 /></td></tr><br />
			<tr><td>Descripción:  <textarea rows="4" cols="60" name="descripcion_car" MAXLENGTH=1000></textarea></td></tr><br />
        		<tr><td><input type="submit" value="Agregar"></td></tr>
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

