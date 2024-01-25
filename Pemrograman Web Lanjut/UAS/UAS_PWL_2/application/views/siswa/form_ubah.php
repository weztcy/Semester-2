<html>
  <head>
    <title>Form Ubah - CRUD Codeigniter</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
  </head>
  <body style="margin: 0px 500px;color:white;background-color:#404040;">
  <br><br><br><br>
    <h1 style="text-align:center ; color:yellow">Edit Student Data</h1>
    <hr class="border border-warning border-3">
    <!-- Menampilkan Error jika validasi tidak valid -->
    <div style="color: red;"><?php echo validation_errors(); ?></div>
    <?php echo form_open("siswa/ubah/".$siswa->nim); ?>
      <table cellpadding="15" style="margin: 0px 29px;">
        <tr>
          <td>NIM</td>
          <td><input type="text" name="input_nim" value="<?php echo set_value('input_nim'); ?>"></td>
        </tr>
        <tr>
          <td>Nama</td>
          <td><input type="text" name="input_nama" value="<?php echo set_value('input_nama'); ?>"></td>
        </tr>
        <tr>
          <td>Jenis Kelamin</td>
          <td>
            <input type="radio" name="input_jenis_kelamin" value="Laki-Laki" <?php echo set_radio('jenis_kelamin', 'Laki-Laki'); ?>> Laki-Laki &ensp;
            <input type="radio" name="input_jenis_kelamin" value="Perempuan" <?php echo set_radio('jenis_kelamin', 'Perempuan'); ?>> Perempuan
          </td>
        </tr>
        <tr>
          <td>Telepon</td>
          <td><input type="text" name="input_telepon" value="<?php echo set_value('input_telepon'); ?>"></td>
        </tr>
        <tr>
          <td>Alamat</td>
          <td><input type="text" name="input_alamat" value="<?php echo set_value('input_alamat'); ?>"></td>
        </tr>
        <tr>
          <td>Kode Pos</td>
          <td><input type="text" name="input_kode_pos"><?php echo set_value('input_kode_pos'); ?></td>
        </tr>
      </table>
      <hr class="border border-warning border-3">
        <div class="div" style="margin: 0px 35px; float:right">
          <input style="border-radius:0px 10px 0px 10px;padding:5px;width:100px;background-color:aqua" type="submit" name="submit" value="SAVE">&ensp;&ensp;  
          <a href="<?php echo base_url(); ?>"><input style="border-radius:0px 10px 0px 10px;padding:5px;width:100px;background-color:#ff1a1a" type="button" value="CANCEL"></a>
        </div>
  </body>

</html>