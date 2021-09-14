<?php

echo "<b>Tracker DATA!</b><br>";

echo "<pre>";
print_r($_REQUEST);

// using the FILE_APPEND flag to append the content to the end of the file
// and the LOCK_EX flag to prevent anyone else writing to the file at the same time
 
//file_put_contents("data.txt", $_REQUEST, FILE_APPEND | LOCK_EX);

file_put_contents("data.txt", $_REQUEST, FILE_APPEND);
die("<br>DONE!");

?>