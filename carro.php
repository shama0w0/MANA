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

//QUITAR
if(!empty($_GET['quitar']))
	{
		$usr=pg_escape_string($_SESSION["nombre"]);
		$compra = fopen("compras/".$usr.".txt", "r");
		$compraaux=file("compras/".$usr.".txt");
		$cont=0;
		while (!feof($compra)) 
			{
			$bufer = fgets($compra, 4096); 
			$test = explode("/",$bufer);
			if($test[0]==$_GET['quitar'])
				{
				echo $cont.$_GET['quitar'].$test[0]."<br>";
				unset($compraaux[$cont]);
				file_put_contents("compras/".$usr.".txt", join('', $compraaux)); 
				}
			$cont++;
			}
		Header("Location: carro.php"); 	
	}


//VACIAR
if(!empty($_GET['quitart']))
	{
	$usr=pg_escape_string($_SESSION["nombre"]);
	fopen("compras/".$usr.".txt",'w+');
	Header("Location: carro.php"); 	
	}
//COMPRAR
if(!empty($_GET['comprar']))
	{
	if($_GET['nom']==null||$_GET['nom']==" "||$_GET['r']==null||$_GET['r']==" ")
		{
		?> 
		<script language="javascript">
		alert("LOS DATOS DEL CLIENTEN DEBEN SER SELECCIONADOS O INGRESADOS"); 
		</script>
		<?php
		}
		else{
			$usr=pg_escape_string($_SESSION["nombre"]);
			$compra = fopen("compras/".$usr.".txt", "r");
			while (!feof($compra)) 
				{
				$bufer = fgets($compra, 4096); 
				$test = explode("/",$bufer);
				if($test[0]!=NULL)
					{
					$con = pg_connect($cadena) or die( "Error al conectar".pg_last_error() );	
					$consulta = "SELECT * FROM productos WHERE codigo='" . $test[0] . "'";	
					$result = pg_query($consulta) or die("Error query".pg_last_error() );
					$row = pg_fetch_array($result, null, PGSQL_ASSOC);			
					$nueva_cantidad=$row['cantidad']-$test[1];
					if($nueva_cantidad<0){$nueva_cantidad=0;}
					$consulta2 = "UPDATE productos SET cantidad='" . pg_escape_string ($nueva_cantidad) . "' WHERE codigo='" . $test[0] . "'";	
					$result2 = pg_query($consulta2) or die("Error query".pg_last_error() );
					}
				}
				?> <script language="javascript">
				alert("COMPRA REALIZADA");
				</script>
				<?php	
				$fecha_hora=date("d-m-Y H:i:s");
				$consulta2 = "INSERT INTO facturas (cliente, rut, nombre_vendedor, precio, cantidad, productos, fecha) VALUES ('" . $_GET['nom'] . "','" . $_GET['r'] . "','" . $_SESSION["nombre"] . "','" . $_GET["pt"] . "','" . $_GET["ct"] . "',' ','" . $fecha_hora . "')";
				$result2 = pg_query($consulta2) or die("Error query".pg_last_error() );			
				fopen("compras/".$usr.".txt",'w+');		
				}
		Header("refresh:3; url=vender.php");
	}


if(isset($_SESSION['nombre']))
			{ ?>
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
<center>
<div class="CSSTableGenerator" >
			<?php  
			$con = pg_connect($cadena) or die( "Error al conectar".pg_last_error() );	
			$consulta = "SELECT * FROM clientes ORDER BY nombre";	
			$result = pg_query($consulta) or die("Error query".pg_last_error() );
			
			?>
                <table >
				<form id="login" action="carro.php" method= "post" style="margin:0px;">
				<label for="clientes">CLIENTE PARA LA VENTA</label> <br/>
				<select id="clientes" name="cliente">
					<option value="" selected="selected">SELECCIONE UN CLIENTE</option>
					<?
					while ($row_cliente = pg_fetch_array($result, null, PGSQL_ASSOC)):
					?>
					<option value="<?php  echo  $row_cliente['nombre']?>"><?php  echo  $row_cliente['nombre']?></option>					
					<?
					endwhile;
					?>
					<option value="otro">OTRO</option>
				</select> 
				&nbsp;&nbsp;&nbsp;
				<INPUT TYPE="submit" NAME="OK" VALUE="Mostrar">
				</form>
				<br/> <br/>
				<?
				if(isset($_POST['cliente'])){
					if($_POST['cliente']=="otro")
						{
						
						echo "Nombre: ";
						?><input type='text' size="40" name='nombre_cliente' MAXLENGTH=50 />
						&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
						<?	
						echo "Rut: ";
						?><input type='text' size="20" name='rut_cliente' MAXLENGTH=11 /><br><?
						echo "Direccion: ";
						?><input type='text' size="50" name='direccion_cliente' MAXLENGTH=200 />
						&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<?
						echo "Descuento: ";
						?><input type='text' size="5" name='descuento_cliente' MAXLENGTH=2 /><br><?
						}else
							{
							$con = pg_connect($cadena) or die( "Error al conectar".pg_last_error() );	
							$consulta = "SELECT * FROM clientes WHERE nombre='" . $_POST['cliente']. "'";	
							$result = pg_query($consulta) or die("Error query".pg_last_error() );
							$row_cliente = pg_fetch_array($result, null, PGSQL_ASSOC);
							echo "Nombre: ".$row_cliente['nombre']."<br>";
							?><input type="hidden" name="nombre_cliente" value=<?php  echo  $row_cliente['nombre']?> /><?
							echo "Rut: ".$row_cliente['rut']."<br>";
							?><input type="hidden" name="rut_cliente" value=<?php  echo  $row_cliente['rut']?> /><?
							echo "Direccion: ".$row_cliente['direccion']."<br>";
							?><input type="hidden" name="direccion_cliente" value=<?php  echo  $row_cliente['direccion']?> /><?
							echo "Descuento: ".$row_cliente['descuento']."<br>";
							?><input type="hidden" name="descuento_cliente" value=<?php  echo  $row_cliente['descuento']?> /><?
							}
							
				}
				?>
				
				 <br/> <br/>
                    <tr>
					                        <td width="70">
                            <font size="+1">Codigo</font>
                        </td>
                        <td width="650">
                            <font size="+1">Productos</font>
                        </td>
                        <td width="70">
                            <font size="+1">Cantidad</font>
                        </td>
                        <td width="70">
                            <font size="+1">Precio</font>
                        </td>
                        <td width="100">
                            <font size="+1">Opciones</font>
                        </td>
                    </tr> 
					
<!-- LEER TXT DE COMPRA-->
<?
$usr=pg_escape_string($_SESSION["nombre"]);
$compra = fopen("compras/".$usr.".txt", "r");
$totalcantidad=0;
$totalprecio=0;
			while (!feof($compra)) 
				{
				$bufer = fgets($compra, 4096); 
				$test = explode("/",$bufer);
				if($test[0]!=NULL){
					$totalcantidad=$totalcantidad+$test[1];
					$con = pg_connect($cadena) or die( "Error al conectar".pg_last_error() );	
					$consulta = "SELECT * FROM productos WHERE codigo='" . $test[0] . "'";	
					$result = pg_query($consulta) or die("Error query".pg_last_error() );
					$row = pg_fetch_array($result, null, PGSQL_ASSOC);			
					$totalprecio=$totalprecio+($row['precio']*$test[1]);
?>
                    <tr>
					     <td >
                            <font size="+1"><?php  echo  $row['codigo']?></font>
                        </td>
                        <td >
                            <font size="+1"><?php  echo  $row['nombre']?></font>
                        </td>
                        <td>
                            <font size="+1"><?php  echo  $test[1]?></font>
                        </td>
                        <td> 
                            <font size="+1"><?php  echo  $row['precio']?></font>
                        </td>
                        <td width="70">
						 <center>
						 <input type="button" value="Quitar" onClick="location.href='carro.php?quitar=<?php echo $row['codigo'];?>'">
                         </center>
						</td>

                    </tr>
				<?}}fclose ($compra);?>
<!-- FIN  DE LEER TXT DE COMPRA-->

					<tr>                     
						<td >
                           
                        </td>
						<td >
                        </td>
                        <td>
							<font size="+1">	Total: <? echo $totalcantidad?></font>
							<input type="hidden" name="cantidad_t" value=<?php  echo  number_format($totalcantidad)?> />
                        <td> 
                            <font size="+1">	Total: $<? echo number_format($totalprecio)?></font>
							<input type="hidden" name="precio_t" value=<?php  echo  number_format($totalprecio)?> />
                        </td>
						<td >
        	<input type="button" style="width:100px; height:30px; font-size:12pt" value="COMPRAR" onClick="location.href='carro.php?comprar=1&ct=<? echo number_format($totalcantidad)?>&pt=<? echo $totalprecio?>&nom=<? echo $row_cliente['nombre']?>&r=<? echo $row_cliente['rut']?>'">

						</td>

                    </tr>


                </table>
	</br>
	<h4 style="text-align:center">
			<input type="reset" style="width:130px; height:30px; font-size:12pt" value="Vaciar Carro" onClick="location.href='carro.php?quitart=1'">
	</h4>
            </div>
 </center>           

	</div>&nbsp;
	<!-- end #page -->
</div>

<!-- end #footer -->
<?php

} else{ header("refresh:0; url=index.php");exit;} ?>
</body>
</html>

