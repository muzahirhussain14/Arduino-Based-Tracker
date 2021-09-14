<?php

echo "<b>Tracker DATA!</b><br>";

//Get the request method.
$requestType = $_SERVER['REQUEST_METHOD'];
 
//Switch statement
switch ($requestType) {
    case 'POST':

      break;
    
	case 'GET':
	  $data = file_get_contents("data.txt");
      $jsonData = json_encode($data);
      echo $jsonData;									// return data
      break;    
    
	default:
      //request type that isn't being handled.
      break;
}

die("<br>DONE!");

?>