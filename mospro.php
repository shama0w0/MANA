
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
			 <h4 style="text-align:right">
			<form method="get" action="buscar.php" >
							Buscador: <input type="text" name="n" id="search-text" value="" />
			</form>
 			</h4>
			
<div class="CSSTableGenerator" >

                <table >
                    <tr>
                        <td width="70">
                            <font size="+1">Codigo</font>
                        </td>
                        <td width="620">
                            <font size="+1">Nombre producto</font>
                        </td>
                        <td width="30">
                            <font size="+1">Cantidad</font>
                        </td>
                        <td width="300">
                            <font size="+1">Opciones</font>
                        </td>
                    </tr> 
                    <tr>
                        <td >
                            <font size="+1">Row 1</font>
                        </td>
                        <td >
                            <font size="+1">Row 1</font>
                        </td>
                        <td>
                            <font size="+1">Row 1</font>
                        </td>

                        <td width="70">
                        
						 <center>
						 <input type="text" name="cantidad" size="5" MAXLENGTH=10/>
						 <input type="button" value="+" 
						    onClick="var strRazon=prompt('Hola ¿cuál es la razon del cambio de stock?','');
						    if(strRazon!=null && strRazon!='')
						               {
						               alert('Stock Cambiado');
						               }
						               else
						                    {
						                    if(strRazon==''){
						                    alert('Debe ingresar una razón');}
						                    }
						  ">
						 <input type="button" value="-" 
						    onClick="var strRazon=prompt('Hola ¿cuál es la razón del cambio de stock?','');
						    if(strRazon!=null && strRazon!='')
						               {
						               alert('Stock Cambiado');
						               }
						               else
						                    {
						                    if(strRazon==''){
						                    alert('Debe ingresar una razón');}
						                    }
						  ">
                          <input type="button" value="Ver" onClick="location=''">
						 
						  
						  <input type="button" value="Eliminar" 
						    onClick="var strRazon=prompt('Hola ¿cuál es la razón del cambio de la eliminación?','');
						    if(strRazon!=null && strRazon!='')
						               {
						               if(confirm('CONFIRMACIÓN: ¿En verdad desea eliminar este producto?')) location=''
						               }
						               else
						                    {
						                    if(strRazon==''){
						                    alert('Debe ingresar una razon');}
						                    }
						  ">
						  
                         </center>
						</td>
                    </tr>
                    <tr>
                        <td >
                           
                        </td>
                        <td >
                           
                        </td>
                        <td>
                         
                        </td>

                        <td width="70">
						 <center>
						 <input type="text" name="cantidad" size="5" MAXLENGTH=10/>
						 <input type="button" value="+" 
						    onClick="var strRazon=prompt('Hola ¿cuál es la razon del cambio de stock?','');
						    if(strRazon!=null && strRazon!='')
						               {
						               alert('Stock Cambiado');
						               }
						               else
						                    {
						                    if(strRazon==''){
						                    alert('Debe ingresar una razón');}
						                    }
						  ">
						 <input type="button" value="-" 
						    onClick="var strRazon=prompt('Hola ¿cuál es la razón del cambio de stock?','');
						    if(strRazon!=null && strRazon!='')
						               {
						               alert('Stock Cambiado');
						               }
						               else
						                    {
						                    if(strRazon==''){
						                    alert('Debe ingresar una razón');}
						                    }
						  ">
                          <input type="button" value="Ver" onClick="location=''">
						 
						  
						  <input type="button" value="Eliminar" 
						    onClick="var strRazon=prompt('Hola ¿cuál es la razón del cambio de la eliminación?','');
						    if(strRazon!=null && strRazon!='')
						               {
						               if(confirm('CONFIRMACIÓN: ¿En verdad desea eliminar este producto?')) location='mospro.php'
						               }
						               else
						                    {
						                    if(strRazon==''){
						                    alert('Debe ingresar una razon');}
						                    }
						  ">
						  
                         </center>
						</td>
                    </tr>
					<tr>
                        <td >
                           
                        </td>
                        <td >
                           
                        </td>
                        <td>
                           
                        </td>

                        <td width="70">
						 <center>
						 <input type="text" name="cantidad" size="5" MAXLENGTH=10/>
						 <input type="button" value="+" 
						    onClick="var strRazon=prompt('Hola ¿cuál es la razon del cambio de stock?','');
						    if(strRazon!=null && strRazon!='')
						               {
						               alert('Stock Cambiado');
						               }
						               else
						                    {
						                    if(strRazon==''){
						                    alert('Debe ingresar una razón');}
						                    }
						  ">
						 <input type="button" value="-" 
						    onClick="var strRazon=prompt('Hola ¿cuál es la razón del cambio de stock?','');
						    if(strRazon!=null && strRazon!='')
						               {
						               alert('Stock Cambiado');
						               }
						               else
						                    {
						                    if(strRazon==''){
						                    alert('Debe ingresar una razón');}
						                    }
						  ">
                          <input type="button" value="Ver" onClick="location=''">
						 
						  
						  <input type="button" value="Eliminar" 
						    onClick="var strRazon=prompt('Hola ¿cuál es la razón del cambio de la eliminación?','');
						    if(strRazon!=null && strRazon!='')
						               {
						               if(confirm('CONFIRMACIÓN: ¿En verdad desea eliminar este producto?')) location='mospro.php'
						               }
						               else
						                    {
						                    if(strRazon==''){
						                    alert('Debe ingresar una razon');}
						                    }
						  ">
						  
                         </center>
						</td>
                    </tr>
					<tr>
                        <td >
                           
                        </td>
                        <td >
                           
                        </td>
                        <td>
                          
                        </td>

                        <td width="70">
						 <center>
						 <input type="text" name="cantidad" size="5" MAXLENGTH=10/>
						 <input type="button" value="+" 
						    onClick="var strRazon=prompt('Hola ¿cuál es la razon del cambio de stock?','');
						    if(strRazon!=null && strRazon!='')
						               {
						               alert('Stock Cambiado');
						               }
						               else
						                    {
						                    if(strRazon==''){
						                    alert('Debe ingresar una razón');}
						                    }
						  ">
						 <input type="button" value="-" 
						    onClick="var strRazon=prompt('Hola ¿cuál es la razón del cambio de stock?','');
						    if(strRazon!=null && strRazon!='')
						               {
						               alert('Stock Cambiado');
						               }
						               else
						                    {
						                    if(strRazon==''){
						                    alert('Debe ingresar una razón');}
						                    }
						  ">
                          <input type="button" value="Ver" onClick="location=''">
						 
						  
						  <input type="button" value="Eliminar" 
						    onClick="var strRazon=prompt('Hola ¿cuál es la razón del cambio de la eliminación?','');
						    if(strRazon!=null && strRazon!='')
						               {
						               if(confirm('CONFIRMACIÓN: ¿En verdad desea eliminar este producto?')) location='mospro.php'
						               }
						               else
						                    {
						                    if(strRazon==''){
						                    alert('Debe ingresar una razon');}
						                    }
						  ">
						  
                         </center>
						</td>
                    </tr>
					<tr>
                        <td >
                           
                        </td>
                        <td >
                          
                        </td>
                        <td>
                          
                        </td>

                        <td width="70">
						 <center>
						 <input type="text" name="cantidad" size="5" MAXLENGTH=10/>
						 <input type="button" value="+" 
						    onClick="var strRazon=prompt('Hola ¿cuál es la razon del cambio de stock?','');
						    if(strRazon!=null && strRazon!='')
						               {
						               alert('Stock Cambiado');
						               }
						               else
						                    {
						                    if(strRazon==''){
						                    alert('Debe ingresar una razón');}
						                    }
						  ">
						 <input type="button" value="-" 
						    onClick="var strRazon=prompt('Hola ¿cuál es la razón del cambio de stock?','');
						    if(strRazon!=null && strRazon!='')
						               {
						               alert('Stock Cambiado');
						               }
						               else
						                    {
						                    if(strRazon==''){
						                    alert('Debe ingresar una razón');}
						                    }
						  ">
                          <input type="button" value="Ver" onClick="location=''">
						 
						  
						  <input type="button" value="Eliminar" 
						    onClick="var strRazon=prompt('Hola ¿cuál es la razón del cambio de la eliminación?','');
						    if(strRazon!=null && strRazon!='')
						               {
						               if(confirm('CONFIRMACIÓN: ¿En verdad desea eliminar este producto?')) location='mospro.php'
						               }
						               else
						                    {
						                    if(strRazon==''){
						                    alert('Debe ingresar una razon');}
						                    }
						  ">
						  
                         </center>
						</td>
                    </tr>
					<tr>
                        <td >
                            
                        </td>
                        <td >
                           
                        </td>
                        <td>
                           
                        </td>

                        <td width="70">
						 <center>
						 <input type="text" name="cantidad" size="5" MAXLENGTH=10/>
						 <input type="button" value="+" 
						    onClick="var strRazon=prompt('Hola ¿cuál es la razon del cambio de stock?','');
						    if(strRazon!=null && strRazon!='')
						               {
						               alert('Stock Cambiado');
						               }
						               else
						                    {
						                    if(strRazon==''){
						                    alert('Debe ingresar una razón');}
						                    }
						  ">
						 <input type="button" value="-" 
						    onClick="var strRazon=prompt('Hola ¿cuál es la razón del cambio de stock?','');
						    if(strRazon!=null && strRazon!='')
						               {
						               alert('Stock Cambiado');
						               }
						               else
						                    {
						                    if(strRazon==''){
						                    alert('Debe ingresar una razón');}
						                    }
						  ">
                          <input type="button" value="Ver" onClick="location=''">
						 
						  
						  <input type="button" value="Eliminar" 
						    onClick="var strRazon=prompt('Hola ¿cuál es la razón del cambio de la eliminación?','');
						    if(strRazon!=null && strRazon!='')
						               {
						               if(confirm('CONFIRMACIÓN: ¿En verdad desea eliminar este producto?')) location='mospro.php'
						               }
						               else
						                    {
						                    if(strRazon==''){
						                    alert('Debe ingresar una razon');}
						                    }
						  ">
						  
                         </center>
						</td>
                    </tr>				

                </table>
            </div>
            
&nbsp
<div align="center">
<a href="javascript:history.go(-1)"><font size="+1">Atrás</font> </a><------><a href="moscar.php?pag="  ><font size="+1">Siguiente</font></a>
</div>

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

