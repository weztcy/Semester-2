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

if (isset($_GET['id'])) {
    $kode = $_GET['id'];
    $query = "select * from barang where kode_barang=$kode";
    $sql = mysqli_query($conn, $query);
    while ($hasil = mysqli_fetch_array($sql)) {
        $kode = $hasil['kode_barang'];
        $nama_barang = ($hasil['nama']);
        $gambar = ($hasil['gambar']);
        $harga = $hasil['harga'];
        $stok = $hasil['jml_stok'];
    }
} else {
    die("Error. NO Id Selected! ");
}
if (isset($_POST['sub'])) {
    $ekstensi_diperbolehkan = array('png', 'jpg');
    $query = "select * from barang where kode_barang=$kode";
    $sql = mysqli_query($conn, $query);
    while ($hasil = mysqli_fetch_array($sql)) {
        $gambarLama = ($hasil['gambar']);
    }
    $gambar = $_FILES['gambar']['name'];
    $x = explode('.', $gambar);
    $ekstensi = strtolower(end($x));
    $file_tmp = $_FILES['gambar']['tmp_name'];
    if ($gambar = $_FILES['gambar']['name'] == "" || $gambar = $_FILES['gambar']['name'] == null) {
        $nama_barang = $_POST['nama'];
        $harga = $_POST['harga'];
        $stok = $_POST['stok'];
        $gambar = $gambarLama;
        move_uploaded_file($file_tmp, 'images/' . $gambar);
        $sql = "UPDATE barang SET nama='$nama_barang', gambar='$gambar', harga=$harga, jml_stok=$stok WHERE kode_barang=$kode";
        $result = mysqli_query($conn, $sql);
        if ($result) {
            echo "<script>alert('Data berhasil diupdate!')</script>";
        } else {
            echo "<script>alert('Data gagal ditambahkan!')</script>";
        }
    } else {
        $nama_barang = $_POST['nama'];
        $harga = $_POST['harga'];
        $stok = $_POST['stok'];
        $gambar = $_FILES['gambar']['name'];
        if (in_array($ekstensi, $ekstensi_diperbolehkan) === true) {
            move_uploaded_file($file_tmp, 'images/' . $gambar);
            $sql = "UPDATE barang SET nama='$nama_barang', gambar='$gambar', harga=$harga, jml_stok=$stok WHERE kode_barang=$kode";
            $result = mysqli_query($conn, $sql);
            if ($result) {
                echo "<script>alert('Data berhasil diupdate!')</script>";
            } else {
                echo "<script>alert('Data gagal ditambahkan!')</script>";
            }
        } else {
            echo '<div class="alert alert-danger">Ekstensi gambar yang diperbolehkan hanya .jpg dan .png</div>';
        }
    }
}
?>
<html>

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <title>Edit Barang</title>
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
            background: #F5F7FA;
            font-family: 'Open Sans', sans-serif;
        }

        img {
            max-width: 50%;
            height: auto;
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
                                <input type="text" class="form-control" name="n1" value="<?php echo $kode; ?>" disabled>
                            </div>
                            <div class="form-group">
                                <label>Nama Barang</label>
                                <input type="text" class="form-control" name="nama" value="<?php echo $nama_barang; ?>">
                            </div>
                            <div class="form-group">
                                <label>Gambar</label>
                                <br>
                                <img src="images/<?php echo $gambar ?>">
                                <br>
                                <br>
                                <input type="file" name="gambar" value="<?php echo $gambar; ?>">
                            </div>
                            <div class="form-group">
                                <label>Harga Jual</label>
                                <input type="text" class="form-control" name="harga" value="<?php echo $harga; ?>">
                            </div>
                            <div class="form-group">
                                <label>Stok</label>
                                <input type="text" class="form-control" name="stok" value="<?php echo $stok; ?>">
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