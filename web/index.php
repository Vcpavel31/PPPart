<?php
$MacroList = [
    "CategoryList" => "SELECT `Categories`.ID AS 'ID', `Categories`.`Name` AS 'Name', `Categories_Arrangement`.`Ordered` AS 'Ordered'
                        FROM `Categories`, `Categories_Arrangement`
                        WHERE `Categories`.ID = `Categories_Arrangement`.`Category`
                            AND `Categories`.`Hidden` = 0",
    
    "Attributes" => [
        "SELECT `Attributes`.*
            FROM `Attributes`, `Categories_Attributes`, `Categories_Arrangement`
            WHERE `Attributes`.`ID` = `Categories_Attributes`.`Attributes`
                AND `Categories_Attributes`.`Hidden` = 0
                AND `Categories_Attributes`.`Category` = `Categories_Arrangement`.`Category`
                AND (`Categories_Arrangement`.`Category` = ",
        ")
            ORDER BY `Attributes`.`ID` ASC"
    ],

    "Attribut" => [
        "SELECT `Attribute`.`Attribute_Info`,`Attribute`.`Attribute_Date`,`Attribute`.`Attribute_Value` AS 'Attribute_Value', `Attributes`.`Attribute_Name` AS 'Attribute_Name'
            FROM `Attribute`,`Attributes`
            WHERE `Attribute`.`Item_ID` = ",
        "
                AND `Attributes`.`ID` = `Attribute`.`Attribute_Option`"
    ],

    "Item_Amount" => [
        "SELECT `Amount`,`Date`
            FROM `Amounts`
            WHERE `Item_ID` = '",
        "' ORDER BY `Amounts`.`Date` DESC LIMIT 1"
    ],
    
    "Item_Attributes" => [
        "SELECT `Attributes`.`Attribute_Name` AS 'Name', `Attribute`.`Attribute_Value` AS 'Value', `Attribute`.`Attribute_Info` AS 'Info', `Attribute`.`Attribute_Date` AS 'Date'
            FROM `Attribute`, `Attributes`
            WHERE `Attributes`.`ID` = `Attribute`.`Attribute_Option`
                AND `Item_ID` = "
    ],

    "Amount_Count" => [
        "SELECT COUNT(`ID`)
            FROM `Amounts`
            WHERE `Item_ID` = "
    ],

    "All_Amounts" => [
        "SELECT `Amount`,`Date`
            FROM `Amounts`
            WHERE `Item_ID` = '",
        "' ORDER BY `Amounts`.`Date` DESC"
    ],

    "Amount_Range" => [
        "SELECT IF( MIN(`Amount`) >= 50, MIN(`Amount`)*0.95, 0 ) AS 'Min_Amount', MAX(`Amount`)*1.1 AS 'Max_Amount',
                ( MIN(`Date`)- INTERVAL 1 DAY ) AS 'Min_Date', IF( MAX(`Date`)+ INTERVAL 1 DAY >= CURRENT_TIMESTAMP, CURRENT_TIMESTAMP, MAX(`Date`)+ INTERVAL 1 DAY ) AS 'Max_Date'
            FROM `Amounts`
            WHERE `Item_ID` = "
    ]
];



$dbServername = "innodb.endora.cz";
$dbName = "vcpave1644611634";
$dbPort = 3306;

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $Debug = $_POST["Debug"] === "True";
    if ($Debug) print_r($_POST);

    $dbUsername = $_POST["User"];
    $dbPassword = $_POST["Pass"];
    $dbQuery = $_POST["Query"];

    $conn = new PDO("mysql:host=$dbServername;port=$dbPort;dbname=$dbName", $dbUsername, $dbPassword);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); // enable error handling and logging

    if (substr($dbQuery, 0, 5) === "MACRO") {
        $pieces = explode("(", trim($dbQuery, ')'));
        if (count($pieces) < 2) {
            throw new Exception("Wrong MACRO Suffix"); // handle error and log message
        } elseif (count($pieces) == 2) {
            $dbQuery = $MacroList[$pieces[1]];
        } else {
            $dbQuery = $MacroList[$pieces[1]][0];
            for ($i = 0; $i <= count($pieces) - 2; $i++) {
                $dbQuery = $dbQuery . $pieces[$i + 2] . $MacroList[$pieces[1]][$i + 1];
            }
        }
    }

    if (substr($dbQuery, 0, 6) === "INSERT") {
        $stmt = $conn->prepare($dbQuery);
        try {
            if ($stmt->execute()) {
                $last_id = $conn->lastInsertId();
                echo "New record created successfully. Last inserted ID is: " . $last_id;
            } else {
                $errorInfo = $stmt->errorInfo();
                throw new Exception("Error: " . $errorInfo[2]); // handle error and log message
            }
        } catch (Exception $e) {
            error_log($e->getMessage()); // log error message
            echo $e->getMessage();
        }
    } else {
        $stmt = $conn->prepare($dbQuery);
        try {
            if ($stmt->execute()) {
                $result = $stmt->fetchAll(PDO::FETCH_ASSOC);
                foreach ($result as $row) {
                    print_r($row);
                }
            } else {
                $errorInfo = $stmt->errorInfo();
                throw new Exception("Error: " . $errorInfo[2]); // handle error and log message
            }
        } catch (Exception $e) {
            error_log($e->getMessage());
        }
    }

    $conn = null;
}
else {
    echo "No data posted with HTTP POST.";
}
