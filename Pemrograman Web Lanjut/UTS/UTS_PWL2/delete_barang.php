<?php

session_start();

include 'koneksi.php';

//empty does both of the checks you are doing at once
//check if user is logged in first
if(empty($_SESSION['email'])) {

    //give error and start redirection to login page
    //you may never see this `echo` because the redirect may happen too fast
    echo "Please log in first to see this page.";
    header('Location: login.php');

    //kill page because user is not logged in and is waiting for redirection
    die();
}

if($_SESSION['peran'] != 'admin') {
    die("Access Denied, you're not admin!");
}

echo "Welcome to the member's area, " . $_SESSION['email'] . "!";

if (isset($_GET['id'])) {
    $kode = $_GET['id'];
} else {
    die("Error. NO Id Selected! ");
}
?>
<html>

<head>
    <title>Delete Barang</title>
</head>

<body>
    <?php
    //proses delete barang
    if($_SESSION['peran'] == 'admin') {
        if (!empty($kode) && $kode != "") {
            $query = "DELETE FROM barang WHERE kode_barang=$kode";
            $gambar=$_GET["gambar"];
            $sql = mysqli_query($conn, $query);
            if ($sql) {
                echo "<h2><font color=blue>Barang telah berhasil dihapus</font></h2>";
            } else {
                echo "<h2><font color=red>Barang gagaldihapus</font></h2>";
            }
            unlink("images/".$gambar);
            echo "Klik <a href='home.php'>di
    sini</a> untuk kembali ke halaman display barang";
    
            header("Location: home.php");
        } else {
            die("Access Denied");
        }
    } else {
        die("Access Denied");
    }
    ?>
</body>

</html>