<?php
session_start();

include 'koneksi.php';

//empty does both of the checks you are doing at once
//check if user is logged in first
if (empty($_SESSION['email'])) {

    //give error and start redirection to login page
    //you may never see this `echo` because the redirect may happen too fast
    echo "Please log in first to see this page.";
    header('Location: login.php');

    //kill page because user is not logged in and is waiting for redirection
    die();
}

if ($_SESSION['peran'] != 'admin') {
    die("Access Denied, you're not admin!");
}

if (isset($_POST['sub'])) {
    $ekstensi_diperbolehkan = array('png', 'jpg');
    $gambar = $_FILES['gambar']['name'] ?? null;
    $x = explode('.', $gambar);
    $ekstensi = strtolower(end($x));
    $file_tmp = $_FILES['gambar']['tmp_name'];
    if (empty($gambar)) {
        echo "<script>alert('Please choose a file..!')</script>";
    } else {
        $kode = $_POST['kode'];
        $nama_barang = $_POST['nama'];
        $harga = $_POST['harga'];
        $stok = $_POST['stok'];
        if (in_array($ekstensi, $ekstensi_diperbolehkan) === true) {
            move_uploaded_file($file_tmp, 'images/' . $gambar);
            $sql = "INSERT INTO barang (kode_barang, nama, harga, jml_stok, gambar) VALUES ($kode, '$nama_barang', $harga, $stok, '$gambar')";
            $result = mysqli_query($conn, $sql);
            if ($result) {
                echo "<script>alert('Data berhasil ditambahkan!')</script>";
            } else {
                echo "<script>alert('Data gagal ditambahkan!')</script>";
            }
        } else {
            echo '<div class="alert alert-danger">Ekstensi gambar yang diperbolehkan hanya .jpg dan .png</div>';
        }
    }
}

?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tambah Barang</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
    <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Roboto|Varela+Round|Open+Sans">
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css">
    <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">
    <script src="https://code.jquery.com/jquery-3.5.1.min.js"></script>
    <script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.0/dist/umd/popper.min.js"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.5.0/js/bootstrap.min.js"></script>
    <style>
        body {
            color: #404E67;
            background: black;
            font-family: 'Open Sans', sans-serif;
        }
    </style>
</head>

<body>
    <div class="container">
        <br>
        <div class="row justify-content-center">
            <div class="col-md-6">
                <div class="card">
                    <header class="card-header">
                        <a href="home.php" class="float-right btn btn-outline-primary mt-1">Kembali ke display barang</a>
                        <h4 class="card-title mt-2">Tambah Barang</h4>
                    </header>
                    <article class="card-body">
                        <form action="" method="POST" enctype="multipart/form-data">
                            <div class="form-group">
                                <label>Kode Barang</label>
                                <input type="text" class="form-control" name="kode" placeholder="">
                            </div>
                            <div class="form-group">
                                <label>Nama Barang</label>
                                <input type="text" class="form-control" name="nama" placeholder="">
                            </div>
                            <div class="form-group">
                                <label>Harga</label>
                                <input type="text" class="form-control" name="harga" placeholder="">
                            </div>
                            <div class="form-group">
                                <input type="file" name="gambar">
                            </div>
                            <div class="form-group">
                                <label>Jumlah Stok</label>
                                <input type="text" class="form-control" name="stok" placeholder="">
                            </div>
                            <div class="form-group">
                                <button type="submit" class="btn btn-primary" name="sub"> Tambah </button>
                                <button type="submit" class="btn btn-secondary" name="res"> Reset </button>
                            </div>
                        </form>
                    </article>
                </div>
            </div>
        </div>
    </div>
</body>

</html>