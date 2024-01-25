<?php
    session_start();

    if( isset($_GET['type'])){
        if($_GET['type'] == 'destroy'){
            unset($_SESSION['cart']);
        }
    }
    
    if(!isset($_SESSION['cart'])){
        $_SESSION['cart'] = [];
	}

    $cart = $_SESSION['cart'];

    if( isset($_GET['name']) && isset($_GET['price']) ){
        /**
         * Logic Cart
         */
        
        // Check if product exist in cart
        $exist = false;
        foreach ($cart as $key => $item) {
            if($item['name'] == $_GET['name']){
                $exist = $key;
            }
        }

        if($exist === false){
            array_push($cart, [
                'name'  => $_GET['name'],
                'qty'  => 1,
                'price' => $_GET['price']
            ]);

            echo "Menambah Produk ke cart!";
        }else {
            $qty = $cart[$exist]['qty'];
            $cart[$exist]['qty'] = (int)$qty + 1;
            echo "Menambah QTY Produk!";
        }
        
        $_SESSION['cart'] = $cart;

        header('Location: cart.php');
    }
    // var_dump($_SESSION['cart']);
?>


<!doctype html>
<html lang="en">

<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.0.0/dist/css/bootstrap.min.css" integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">

    <title>Hello, world!</title>
</head>

<body>
    <h1 class="text-center mt-3">Aorus Gaming Shopping Cart</h1>

    <div class="container">
        <h5>Jenis Barang: <?php echo count($cart) ?></h5>
        <a href="cart.php?type=destroy" class="">Kosongkan Data</a>
        <table class="table table-bordered mt-3 table-dark table-striped">
            <thead>
                <tr>
                    <th scope="col">#</th>
                    <th scope="col">Nama Produk</th>
                    <th scope="col">QTY</th>
                    <th scope="col">Harga</th>
                    <th scope="col">Total</th>
                </tr>
            </thead>
            <tbody>
                <?php 
                    $total = 0;

                    foreach ($cart as $key => $item) {

                    $price = (int)$item['price'] * (int)$item['qty'];
                    $total = $total + $price;
                ?>
                
                <tr>
                    <th scope="row"><?php echo $key+1 ?></th>
                    <td><?php echo $item['name'] ?></td>
                    <td><?php echo $item['qty'] ?></td>
                    <td><?php echo 'Rp. '.number_format($item['price']) ?></td>
                    <td><?php echo 'Rp. '.number_format($price) ?></td>
                </tr>
                <?php } ?>
                <tr>
                    <td colspan="4" class="text-right">Total Harga</td>
                    <td><?php echo 'Rp. '.number_format($total) ?></td>
                </tr>
            </tbody>
        </table>

    </div>

    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/popper.js@1.12.9/dist/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.0.0/dist/js/bootstrap.min.js" integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl" crossorigin="anonymous"></script>
</body>

</html>