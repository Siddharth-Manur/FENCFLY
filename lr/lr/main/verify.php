<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php
    $conn=mysqli_connect("localhost","root","","lr");
    if(!$conn){
        echo"failed to connect";
    }
        $fetched = mysqli_query($conn,"select * from users where email='$_POST[email]' and password='$_POST[passwd]';");
        $row = mysqli_fetch_array($fetched);      
        if($row!=null){
            header("Location: home.html");

        }
        else{
            echo"errorrrr";
        }
    
    ?>
    
</body>
</html>