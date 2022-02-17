<?php

$dbServername = "innodb.endora.cz";
$dbName = "vcpave1644611634";
$dbPort = 3306;
   
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $dbUsername = $_POST["User"];   
    $dbPassword = $_POST["Pass"];
    $dbQuerry = $_POST["Querry"];
    
    $conn = new mysqli($dbServername, $dbUsername, $dbPassword, $dbName, $dbPort);

    if ($conn->connect_error) {
        echo "connection failed.";
        die("Connection failed: " . $conn->connect_error);
    }
    else {
        echo "connection to DB is working <br>";
        if ($result = $conn->query($sql)) {
            $result -> fetch_all(MYSQLI_ASSOC);
            print_r($result);
            $result -> free_result();
        } 
        else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }
        $mysqli -> close();
    }
}
else {
    echo "No data posted with HTTP POST.";
}