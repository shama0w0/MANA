<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1" />
<title>Formulario de Eventos Adversos</title>
<style type="text/css">
@charset "utf-8";
/* CSS Document */
body {
	font-family: Arial, Helvetica, sans-serif;
	font-size: 13px;
	width: 1200px;
	height: auto;
	margin: 0px;	
}
fieldset {
	position: relative;
	float: left;
	width: 100%;
}
legend {
	font-size: 18px;
	font-weight: bold;
	color: #666;
	margin-bottom: 5px;	
	margin-top: 10px;
}

</style>
</head>

<body>

<img src="images/evento-adversos.jpg" width="1000" height="480" border="0" />
<?

require('fpdf/fpdf.php');

$contador = 0; 
$pdf=new FPDF();
$pdf->AddPage();
$pdf->SetFont('Arial','B',18);
$pdf->Cell(0,10,'LISTADO PRODUCTOS EN EL STOCK',0,0,'C');
$pdf->Ln(20);

$pdf->SetFont('Helvetica','I',13);

$cadena = "host='localhost' dbname='b17769837_dsi' user='b17769837_shama' password='bdddoce' ";
$con = pg_connect($cadena) or die( "Error al conectar".pg_last_error() );	
$consulta = "SELECT * FROM productos";	
$result = pg_query($consulta) or die("Error query".pg_last_error() );

$auxcont=1;

while ($row = pg_fetch_array($result, null, PGSQL_ASSOC))
	{
	$pdf->SetFont('Arial','B',13);
	$pdf->Cell(190,10,'Producto N°: '.$auxcont,1,0,'C');
	$pdf->SetFont('Helvetica','I',13); 
	$pdf->Ln(15);
	$pdf->Cell(100,10,'Nombre Producto: '.$row["nombre"]);
	$pdf->Ln(10);
	$pdf->Cell(75,10,'Cantidad: '.$row["cantidad"]);
	$pdf->Cell(75,10,'Codigo: '.$row["codigo"]);
	$pdf->Cell(75,10,'Precio: '.$row["precio"]);
	$pdf->Ln(10);
	
	$pdf->MultiCell(0,10,'Descripcion: '.$row["descripcion"]);
	$pdf->Ln(20);
	++$contador;
	++$auxcont;
	if($contador==3)
		{
		$pdf->AddPage();
		$contador=0;
		}					
	} 

//creacion .pdf
ob_end_clean();
$pdf->Output('listado_stock.pdf','I');
   
?>
</body>
</html> 


