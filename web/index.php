<?php
error_reporting(E_ALL & ~E_NOTICE & ~E_WARNING & ~E_STRICT & ~E_DEPRECATED);

$dbServername = "innodb.endora.cz";
$dbName = "vcpave1644611634";
$dbPort = 3306;
   
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $Debug = $_POST["Debug"];    
    if($Debug == 0) print_r($_POST);

    $dbUsername = $_POST["User"];   
    $dbPassword = $_POST["Pass"];
    $dbQuery = $_POST["Query"];

    $conn = new mysqli($dbServername, $dbUsername, $dbPassword, $dbName, $dbPort);

    if ($conn->connect_error) {
        echo "connection failed.";
        die("Connection failed: " . $conn->connect_error);
    }
    else {
        if($Debug == 0) echo "connection to DB is working <br>";
        if ($result = $conn->query($dbQuery)) {
            while ($row = $result->fetch_assoc()) {
                print_r($row);
            }
            $result -> free();
        } 
        else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }
        $conn -> close();
    }
}
else {
    echo "No data posted with HTTP POST.";
}