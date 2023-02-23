<?php
$MacroList = array("CategoryList" => "SELECT `Categories`.ID AS 'ID', `Categories`.`Name` AS 'Name', `Categories_Arrangement`.`Ordered` AS 'Ordered' FROM `Categories`, `Categories_Arrangement` WHERE `Categories`.ID = `Categories_Arrangement`.`Category` AND `Categories`.`Hidden` = '0'");

//error_reporting(E_ALL & ~E_NOTICE & ~E_WARNING & ~E_STRICT & ~E_DEPRECATED);
$dbServername = "innodb.endora.cz";
$dbName = "vcpave1644611634";
$dbPort = 3306;
   
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $Debug = $_POST["Debug"] === "True";    
    if($Debug) print_r($_POST);

    $dbUsername = $_POST["User"];   
    $dbPassword = $_POST["Pass"];
    $dbQuery = $_POST["Query"];

    $conn = new mysqli($dbServername, $dbUsername, $dbPassword, $dbName, $dbPort);

    if ($conn->connect_error) {
        echo "connection failed.";
        die("Connection failed: " . $conn->connect_error);
    }
    else {
        if($Debug) echo "connection to DB is working <br>";
        if(substr($dbQuery, 0, 5) === "MACRO"){
            $pieces = explode("(", trim($dbQuery, ')'));
            switch (count($pieces)) {
                case 2:
                    $dbQuery = $MacroList[$pieces[1]];
                    break;
                case 3:
                    $dbQuery = $MacroList[$pieces[1]]+$pieces[2];
                    break;
                default:
                   echo "Wrong MACRO Suffix";
            }
        }

        if(substr($dbQuery, 0, 6) === "INSERT"){
            if ($conn->query($dbQuery) === TRUE) {
                $last_id = $conn->insert_id;
                echo "New record created successfully. Last inserted ID is: " . $last_id;
            } else {
                echo "Error: " . $sql . "<br>" . $conn->error . "<br> on Query: " . $_POST["Query"];
            }
        }
        else{
            if ($result = $conn->query($dbQuery)) {
                while ($row = $result->fetch_assoc()) {
                    print_r($row);
                }
                $result -> free();
            } 
            else {
                echo "Error: " . $sql . "<br>" . $conn->error . "<br> on Query: " . $_POST["Query"];
            }
        }
        
        $conn -> close();
    }
}
else {
    echo "No data posted with HTTP POST.";
}