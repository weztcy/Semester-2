<?php if ( ! defined('BASEPATH')) exit('No direct script access allowed');
class SiswaModel extends CI_Model {
  // Fungsi untuk menampilkan semua data siswa
  public function view(){
    return $this->db->get('siswa')->result();
  }
  
  // Fungsi untuk menampilkan data siswa berdasarkan NIS nya
  public function view_by($nim){
    $this->db->where('nim', $nim);
    return $this->db->get('siswa')->row();
  }
  
  // Fungsi untuk validasi form tambah dan ubah
  public function validation($mode){
    $this->load->library('form_validation'); // Load library form_validation untuk proses validasinya
    
    // Tambahkan if apakah $mode save atau update
    // Karena ketika update, nim tidak harus divalidasi
    // Jadi nim di validasi hanya ketika menambah data siswa saja
    if($mode == "save")
      $this->form_validation->set_rules('input_nim', 'nim', 'required');
      $this->form_validation->set_rules('input_nama', 'nama', 'required');
      $this->form_validation->set_rules('input_jenis_kelamin', 'jenis_kelamin', 'required');
      $this->form_validation->set_rules('input_telepon', 'telepon', 'required');
      $this->form_validation->set_rules('input_alamat', 'alamat', 'required');
      $this->form_validation->set_rules('input_kode_pos', 'kode_pos', 'required');
      
    if($this->form_validation->run()) // Jika validasi benar
      return TRUE; // Maka kembalikan hasilnya dengan TRUE
    else // Jika ada data yang tidak sesuai validasi
      return FALSE; // Maka kembalikan hasilnya dengan FALSE
  }
  
  // Fungsi untuk melakukan simpan data ke tabel siswa
  public function save(){
    $data = array(
      "nim" => $this->input->post('input_nim'),
      "nama" => $this->input->post('input_nama'),
      "jenis_kelamin" => $this->input->post('input_jenis_kelamin'),
      "telepon" => $this->input->post('input_telepon'),
      "alamat" => $this->input->post('input_alamat'),
      "kode_pos" => $this->input->post('input_kode_pos'),
    );
    
    $this->db->insert('siswa', $data); // Untuk mengeksekusi perintah insert data
  }
  
  // Fungsi untuk melakukan ubah data siswa berdasarkan NIS siswa
  public function edit($nim){
    $data = array(
      "nim" => $this->input->post('input_nim'),
      "nama" => $this->input->post('input_nama'),
      "jenis_kelamin" => $this->input->post('input_jenis_kelamin'),
      "telepon" => $this->input->post('input_telepon'),
      "alamat" => $this->input->post('input_alamat'),
      "kode_pos" => $this->input->post('input_kode_pos'),
    );
    
    $this->db->where('nim', $nim);
    $this->db->update('siswa', $data); // Untuk mengeksekusi perintah update data
  }
  
  // Fungsi untuk melakukan menghapus data siswa berdasarkan NIS siswa
  public function delete($nim){
    $this->db->where('nim', $nim);
    $this->db->delete('siswa'); // Untuk mengeksekusi perintah delete data
  }
}