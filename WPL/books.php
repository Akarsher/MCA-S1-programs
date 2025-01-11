<?php


$conn = mysqli_connect("localhost", "root", "", "muthoot");
if (!$conn) {
  die("Connection failed: " . mysqli_connect_error());
}

echo "Connected successfully.<br>";


if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $title = $_POST['title'];
    $authors = $_POST['authors'];
    $edition = $_POST['edition'];
    $publisher = $_POST['publisher'];
    
    $sql = "INSERT INTO books (title, authors, edition, publisher) VALUES ('$title', '$authors', '$edition', '$publisher')";
    
    if (mysqli_query($conn, $sql)) {
        echo "New record created successfully<br>";
    } else {
        echo "Error: " . $sql . "<br>" . mysqli_error($conn);
    }
}

$search_results = []; 
if (isset($_GET['search_author'])) {
    $search_author = $_GET['search_author'];
    $stmt = mysqli_prepare($conn, "SELECT * FROM books WHERE authors LIKE ?");
    $search_param = "%" . $search_author . "%";
    mysqli_stmt_bind_param($stmt, "s", $search_param);
    mysqli_stmt_execute($stmt);
    $result = mysqli_stmt_get_result($stmt);

    if (mysqli_num_rows($result) > 0) {
        while ($row = mysqli_fetch_assoc($result)) {
            $search_results[] = $row; 
        }

        foreach ($search_results as $search_result) {
            echo "Found: " . $search_result['title'] . " by " . $search_result['authors'] . "<br>";
        }
    } else {
        echo "No results found.<br>";
    }

    mysqli_stmt_close($stmt);
}

mysqli_close($conn);
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Book Store</title>
</head>
<body>
    <h1>Book Details Form</h1>
    <form action="" method="POST">
        <label for="title">Title:</label>
        <input type="text" name="title" required><br>
        <label for="authors">Authors:</label>
        <input type="text" name="authors" required><br>
        <label for="edition">Edition:</label>
        <input type="text" name="edition"><br>
        <label for="publisher">Publisher:</label>
        <input type="text" name="publisher"><br>
        <input type="submit" value="Submit">
    </form>

    <h2>Search for a Book by Author</h2>
    <form action="" method="GET">
        <label for="search_author">Author Name:</label>
        <input type="text" name="search_author" required>
        <input type="submit" value="Search">
    </form>

    <?php if (!empty($search_results)): ?>
        <h2>Search Results:</h2>
        <?php foreach ($search_results as $book): ?>
            <p>ID: <?php echo $book['id']; ?> - Title: <?php echo $book['title']; ?> - Authors: <?php echo $book['authors']; ?> - Edition: <?php echo $book['edition']; ?> - Publisher: <?php echo $book['publisher']; ?></p>
        <?php endforeach; ?>
    <?php endif; ?>
</body>
</html>
