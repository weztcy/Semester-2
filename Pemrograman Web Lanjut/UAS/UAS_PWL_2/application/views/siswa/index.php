<!DOCTYPE html>
<html>
  <head>
    <title>CRUD Codeigniter</title>
    <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta name="description" content="Creative - Bootstrap 3 Responsive Admin Template">
  <meta name="author" content="GeeksLabs">
  <meta name="keyword" content="Creative, Dashboard, Admin, Template, Theme, Bootstrap, Responsive, Retina, Minimal">
  <link rel="shortcut icon" href="img/favicon.png">
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
  </head>
  <body style="background-color:#404040">
      <center>
      <br><br><br><br>
      <h1 style="color: aqua ;">UDINUS College Student Data</h1>
      <hr>
        <a class="btn btn-success" style="margin-left:1160px ;=" href='<?php echo base_url("siswa/tambah"); ?>'>Add Data</a><br><br>
      <table border="1" cellpadding="7" class="rounded table table-dark table-striped table-bordered border-primary" style="width:1250px">
        <tr>
          <th style="text-align: center;">NIM</th>
          <th style="text-align: center;">Nama</th>
          <th style="text-align: center;">Jenis Kelamin</th>
          <th style="text-align: center;">Telepon</th>
          <th style="text-align: center;">Alamat</th>
          <th style="text-align: center;">Kode Pos</th>
          <th style="text-align: center;" colspan="2">Option</th>
        </tr>
        <?php
        if( ! empty($siswa)){ // Jika data siswa tidak sama dengan kosong, artinya jika data siswa ada
          foreach($siswa as $data){
            echo "<tr style='text-align: center;'>
            <td>".$data->nim."</td>
            <td>".$data->nama."</td>
            <td>".$data->jenis_kelamin."</td>
            <td>".$data->telepon."</td>
            <td>".$data->alamat."</td>
            <td>".$data->kode_pos."</td>
            <td><a href='".base_url("siswa/ubah/".$data->nim)."'>Change</a></td>
            <td><a href='".base_url("siswa/hapus/".$data->nim)."'>Delete</a></td>
            </tr>";
          }
        }else{ // Jika data siswa kosong
          echo "<tr><td align='center' colspan='7'>Data Tidak Ada</td></tr>";
        }
        ?>
      </table>
    </center>
  </body>
</html>