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
<?php 
if(isset($_SESSION['nombre']))
			{ 
			
if(isset($_GET['borrar'])) 
	{
		#echo $_GET['borrar'];
		#echo $_GET['why'];
		
		$consulta3 = "SELECT * FROM productos WHERE codigo='" . $_GET['borrar']. "'";	
		$result3 = pg_query($consulta3) or die("Error query".pg_last_error() );
		$row3 = pg_fetch_array($result3, null, PGSQL_ASSOC);	
		
		$fecha_hora=date("d-m-Y H:i:s");
		
		$con = pg_connect($cadena) or die( "Error al conectar".pg_last_error() );
		$consulta = "DELETE FROM productos WHERE codigo='" . $_GET['borrar']. "'";
		$result = pg_query($consulta) or die("Error query".pg_last_error() );
		if ($result)
			{
			$consulta2 = "INSERT INTO logs (origen, nombre_user, razon, nombre_pro, codigo_pro, fecha) VALUES ('borrar_producto','" . $_SESSION["nombre"] . "','" . $_GET['why'] . "','" . $row3['nombre'] . "','" . $row3['codigo'] . "','" . $fecha_hora . "')";
			$result2 = pg_query($consulta2) or die("Error query".pg_last_error() );
			?> <script language="javascript">
			alert("PRODUCTO ELIMINADO"); 
			</script>
			<?php
			header("refresh:0; url=mospro.php");
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

	&nbsp;
	<!-- end #menu -->
	<div id="page">

			<TABLE width="100%"> 
				<tr>
					<td>
						<h4 style="text-align:center">
							<form method="get" action="buscarlog.php" >
								Buscador: <input type="text" name="buscar" id="search-text" value="" />
							</form>
 						</h4>
					</td>
					<td>
						<form action="logtopdf.php" method="post" style="text-align:center">
							<input type=image src="images/pdf.png" width="50" height="50" >
						</form>
					</td>
				</tr>
			</TABLE>
<h4 style="text-align:center">
				<form method="post" action="buscarlog2.php" >
	&nbsp;&nbsp;
			Fecha de Inicio:
			&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
				&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
				&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
				&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
				&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
				
			Fecha de Termino:
						<br>
						Día: 
						<select name=dia1>
						<?echo "<option value='-'></option>";
							for($i=1; $i<=31; $i++) 
							{
							if($i==1||$i==2||$i==3||$i==4||$i==5||$i==6||$i==7||$i==8||$i==9)
								{
								echo "<option value=0$i>0$i</option>";
								}
								else
									{
									echo "<option value=$i>$i</option>";
									}
							}
						?>
						</select> 
						Mes: 
						<select name=mes1>
						<?echo "<option value='-'></option>";
							for($i=1; $i<=12; $i++) 
							{
							if($i==1||$i==2||$i==3||$i==4||$i==5||$i==6||$i==7||$i==8||$i==9)
								{
								echo "<option value=0$i>0$i</option>";
								}
								else
									{
									echo "<option value=$i>$i</option>";
									}
							}
						?>
						</select>
						Año: 
						<select name=anio1>
						<?echo "<option value='-'></option>";
							for($i=2013; $i<=2099; $i++) {
								echo "<option value=$i>$i</option>";
								}
						?>
						</select>
						&nbsp;&nbsp;
						&nbsp;&nbsp;
						y
						&nbsp;&nbsp;
						&nbsp;&nbsp;
									
						Día: 
						<select name=dia2>
						<?echo "<option value='-'></option>";
							for($i=1; $i<=31; $i++) 
							{
							if($i==1||$i==2||$i==3||$i==4||$i==5||$i==6||$i==7||$i==8||$i==9)
								{
								echo "<option value=0$i>0$i</option>";
								}
								else
									{
									echo "<option value=$i>$i</option>";
									}
							}
						?>
						</select> 
						Mes: 
						<select name=mes2>
						<?echo "<option value='-'></option>";
							for($i=1; $i<=12; $i++) 
							{
							if($i==1||$i==2||$i==3||$i==4||$i==5||$i==6||$i==7||$i==8||$i==9)
								{
								echo "<option value=0$i>0$i</option>";
								}
								else
									{
									echo "<option value=$i>$i</option>";
									}
							}
						?>
						</select>
						Año: 
						<select name=anio2>
						<?echo "<option value='-'></option>";
							for($i=2013; $i<=2099; $i++) {
								echo "<option value=$i>$i</option>";
								}
						?>
						</select>			
						
						</td>
				</br>			
				<input type="submit" style="width:160px; height:30px; font-size:12pt" name="buscarlog" value="Buscar por Fecha">			
			</form>
 	</h4>
			<hr style="color: #FFFFFF;" />
			</br>
<center>			
<div class="CSSTableGenerator" >
			<?php  
			$con = pg_connect($cadena) or die( "Error al conectar".pg_last_error() );	
			$consulta = "SELECT * FROM logs ORDER BY fecha desc";	
			$result = pg_query($consulta) or die("Error query".pg_last_error() );	
			?>
                <table >
                    <tr>
                        <td width="70">
                            <font size="+1">Origen</font>
                        </td>
                        <td width="200">
                            <font size="+1">Usuario</font>
                        </td>
                        <td width="600">
                            <font size="+1">Razón</font>
                        </td>
                        <td width="300">
                            <font size="+1">Nombre_P</font>
                        </td>
                        <td width="150">
                            <font size="+1">Codigo_P</font>
                        </td>
                        <td width="200">
                            <font size="+1">Hora y Fecha</font>
                        </td>
                    </tr> 
                    <tr>
					<?
					while ($row = pg_fetch_array($result, null, PGSQL_ASSOC)):
					?>
                        <td >
                            <font size="+1"><?php  echo  $row['origen']?></font>
                        </td>
                        <td >
                            <font size="+1"><?php  echo  $row['nombre_user']?></font>
                        </td>
                        <td>
                            <font size="+1"><?php  echo  $row['razon']?></font>
                        </td>
                        <td >
                            <font size="+1"><?php  echo  $row['nombre_pro']?></font>
                        </td>
                        <td >
                            <font size="+1"><?php  echo  $row['codigo_pro']?></font>
                        </td>
                        <td>
                            <font size="+1"><?php  echo  $row['fecha']?></font>
                        </td>
                    </tr>
				<?	
                  endwhile;  
				?>
                </table>

            </div>
    </center>        
&nbsp
<?
#<div align="center">
#<a href="javascript:history.go(-1)" style="text-decoration:none"><font size="+1" color="FFFFFF" >Atrás</font> </a><------><a href="moscar.php?pag=" style="text-decoration:none" ><font size="+1" color="FFFFFF">Siguiente</font></a>
#</div>
?>
	</div>
	<!-- end #page -->
</div>

<!-- end #footer -->
<?php

} else{ header("refresh:0; url=index.php");exit;} ?>
</body>
</html>

