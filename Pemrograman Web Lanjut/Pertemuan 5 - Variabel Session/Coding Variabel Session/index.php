<?php
    session_start();

    $products = [
        [
            'image'         => 'gallery/Z690 Aorus Xtreme Waterforce 3.png',
            'name'          => 'Z690 Aorus Xtreme Waterforce',
            'description'   => '',
            'price'         => '8900000',
        ],
        [
            'image'         => 'gallery/AORUS GeForce RTX 3090 XTREME 2.png',
            'name'          => 'AORUS GeForce RTX 3090 XTREME',
            'description'   => '',
            'price'         => '12700000',
        ],
        [
            'image'         => 'gallery/AORUS LIQUID COOLER 360 1.png',
            'name'          => 'AORUS LIQUID COOLER 360',
            'description'   => '',
            'price'         => '3100000',
        ],
        [
            'image'         => 'gallery/AORUS Gen4 7000s SSD 2TB 3.png',
            'name'          => 'AORUS Gen4 7000s SSD 2TB',
            'description'   => '',
            'price'         => '5400000',
        ],
        [
            'image'         => 'gallery/AORUS RGB Memory 16GB (2x8GB) 3200MHz 2.png',
            'name'          => 'AORUS RGB Memory 16GB (2x8GB) 3200MHz',
            'description'   => '',
            'price'         => '2200000',
        ],
        [
            'image'         => 'gallery/AORUS P1200W 80+ PLATINUM MODULAR 2.png',
            'name'          => 'AORUS P1200W 80+ PLATINUM MODULAR',
            'description'   => '',
            'price'         => '1500000',
        ],
    ];

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
    <h1 class="text-center mt-3">Aorus Gaming Store</h1>

    <div class="container mt-3">
        <div class="row">
            <?php
                foreach ($products as $key => $item) {
            ?>
            <div class="col-md-4 mt-3 mb-3">
                <div class="card bg-dark text-white" style="width: 18rem; border-radius: 0px 20px 0px 20px">
                    <img class="card-img-top" src="<?php echo $item['image'] ?>" alt="Card image cap">
                    <div class="card-body">
                        <h5 class="card-title"><?php echo $item['name'] ?></h5>
                        <h5 class="card-title"><?php echo 'Rp.'.number_format($item['price']) ?></h5>
                        <p class="card-text"><?php echo substr($item['description'], 0, 50).'' ?></p>
                        <a href="cart.php?name=<?php echo $item['name'] ?>&price=<?php echo $item['price'] ?>" class="btn btn-primary float-right">Add to cart</a>
                    </div>
                </div>
            </div>
            <?php } 
            ?>
        </div>
    </div>

    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/popper.js@1.12.9/dist/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.0.0/dist/js/bootstrap.min.js" integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl" crossorigin="anonymous"></script>
</body>

</html>