<?php

session_start();

include 'koneksi.php';
if (empty($_SESSION['email'])) {
    echo "Please log in first to see this page.";
    header('Location: login.php');
    die();
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Home</title>
    <script language="javascript">
        function tanya() {
            if (confirm("Apakah anda yakin akan menghapus data ini?")) {
                return true;
            } else {
                return false;
            }
        }
    </script>
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

        .table-wrapper {
            width: 700px;
            margin: 30px auto;
            background: #fff;
            padding: 20px;
            box-shadow: 0 1px 1px rgba(0, 0, 0, .05);
        }

        .table-title {
            padding-bottom: 10px;
            margin: 0 0 10px;
        }

        .table-title h2 {
            margin: 6px 0 0;
            font-size: 22px;
        }

        .table-title .add-new {
            float: right;
            height: 30px;
            font-weight: bold;
            font-size: 12px;
            text-shadow: none;
            min-width: 100px;
            border-radius: 50px;
            line-height: 13px;
        }

        .table-title .add-new i {
            margin-right: 4px;
        }

        table.table {
            table-layout: fixed;
        }

        table.table tr th,
        table.table tr td {
            border-color: #e9e9e9;
        }

        table.table th i {
            font-size: 13px;
            margin: 0 5px;
            cursor: pointer;
        }

        table.table th:last-child {
            width: 100px;
        }

        table.table td a {
            cursor: pointer;
            display: inline-block;
            margin: 0 5px;
            min-width: 24px;
        }

        table.table td a.add {
            color: #27C46B;
        }

        table.table td a.edit {
            color: #FFC107;
        }

        table.table td a.delete {
            color: #E34724;
        }

        table.table td i {
            font-size: 19px;
        }

        table.table td a.add i {
            font-size: 24px;
            margin-right: -1px;
            position: relative;
            top: 3px;
        }

        table.table .form-control {
            height: 32px;
            line-height: 32px;
            box-shadow: none;
            border-radius: 2px;
        }

        table.table .form-control.error {
            border-color: #f50000;
        }

        table.table td .add {
            display: none;
        }

        img {
            max-width: 100%;
            height: auto;
        }
    </style>
</head>
<body>
<div class="container-lg">
        
        <div class="table-responsive">
            <div class="table-wrapper bg-success bg-opacity-25 p-4 text-dark" style="border-radius: 0px 20px">
            <p>You're login as <b><?php echo $_SESSION['peran']?></b></p>
                <div class="table-title">
                    <div class="row">
                        <div class="col-sm-8">
                            <h2><b>Menu Makanan Khas Daerah</b></h2>
                        </div>
                        <?php
                        if ($_SESSION['peran'] == "admin") {
                        ?>
                            <div class="col-sm-4">
                                <a href="tambahbarang.php">
                                    <button type="button" class="btn btn-info add-new" style="border-radius: 0px 10px"><i class="fa fa-plus"></i> Tambah Barang</button>
                                </a>
                            </div>
                        <?php
                        }
                        ?>
                    </div>
                </div>
                <table class="table table-borderedc text-center table-dark table-striped">
                    <thead>
                        <tr>
                            <th>Kode Barang</th>
                            <th>Gambar</th>
                            <th>Nama Barang</th>
                            <th>Harga</th>
                            <th>Stok</th>
                            <?php
                            if ($_SESSION['peran'] == 'admin') {
                                echo "<th>Keterangan</th>";
                            }
                            ?>
                        </tr>
                    </thead>
                    <tbody>
                        <?php
                        $query = "SELECT * FROM barang";
                        $sql = mysqli_query($conn, $query);
                        while ($hasil = mysqli_fetch_array($sql)) {
                            $kode = $hasil['kode_barang'];
                            $gambar = $hasil['gambar'];
                            $nama_barang = stripslashes($hasil['nama']);
                            $harga = $hasil['harga'];
                            $stok = $hasil['jml_stok'];
                        ?>
                            <tr>
                                <td><?php echo $kode ?></td>
                                <td><img src="images/<?php echo $gambar?>"></td>
                                <td><?php echo $nama_barang ?></td>
                                <td><?php echo $harga ?></td>
                                <td><?php echo $stok ?></td>
                                <?php
                                if ($_SESSION['peran'] == 'admin') {
                                ?>
                                    <td>
                                        <a class="edit" title="Edit" data-toggle="tooltip" href='editbarang.php?id=<?php echo $kode ?>'><i class="material-icons">&#xE254;</i></a>
                                        <a class="delete" title="Delete" data-toggle="tooltip" href='delete_barang.php?id=<?php echo $kode ?>&gambar=<?php echo $gambar;?>' onClick='return tanya()'><i class="material-icons">&#xE872;</i></a>
                                    </td>
                                <?php
                                }
                                ?>
                            </tr>
                        <?php } ?>
                    </tbody>
                </table>
                <a href="logout.php">
                    <button type="button" class="btn btn-danger" style="border-radius: 0px 10px">Log out</button>
                </a>
            </div>
        </div>
    </div>
</body>
</html>