<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php
        $con=mysqli_connect("localhost","root","","lr");
        if(!$con){
            echo "error";
        }
        mysqli_select_db($con,"lr");
        $query= "insert into users values('$_POST[usrn]','$_POST[passwd]','$_POST[email]');";
        $result=mysqli_query($con,$query);
        if(!$result){
            echo "error while insert";
        }
        else{
            echo "record added successfully";
        }
    ?>
    <a href="index.html">go back to login</a>
    
</body>
</html>