<?php
//procedural dengan mysqli
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "penjualan";
// Create connection
$conn = mysqli_connect(
    $servername,
    $username,
    $password,
    $dbname
);
// Check connection
if (!$conn) {
    die("Failed to connect to MySQL: " .
        mysqli_connect_error());
}
?>