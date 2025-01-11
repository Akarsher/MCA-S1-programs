<?php

$server = "localhost";
$user = "root";
$password = "";
$database = "muthoot";

$conn = mysqli_connect($server, $user, $password, $database);

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

// Create table if it doesn't exist
$sql = "CREATE TABLE IF NOT EXISTS users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(100) NOT NULL,
    age INT NOT NULL
)";
mysqli_query($conn, $sql);

// Handle form submission
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = trim($_POST["name"]);
    $email = trim($_POST["email"]);
    $age = trim($_POST["age"]);

    // Basic validation
    if (!empty($name) && !empty($email) && is_numeric($age) && filter_var($email, FILTER_VALIDATE_EMAIL)) {
        $insert = "INSERT INTO users (name, email, age) VALUES ('$name', '$email', $age)";
        mysqli_query($conn, $insert);
    }
    else {
        echo "details entered are not correct,please enter valid details.";
    }
}

// Retrieve all records
$result = mysqli_query($conn, "SELECT * FROM users");
?>

<!DOCTYPE html>
<html>
<head>
    <title>User Data Form</title>
</head>
<body>
    <h2>User Registration</h2>
    <form method="POST" action="">
        <label>Name:</label><br>
        <input type="text" name="name"><br><br>

        <label>Email:</label><br>
        <input type="text" name="email"><br><br>

        <label>Age:</label><br>
        <input type="text" name="age"><br><br>

        <button type="submit">Submit</button>
    </form>

    <h2>Registered Users</h2>
    <table border="1" cellpadding="5" cellspacing="0">
        <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Email</th>
            <th>Age</th>
        </tr>
        <?php
        if ($result && mysqli_num_rows($result) > 0) {
            while ($row = mysqli_fetch_assoc($result)) {
                echo "<tr>";
                echo "<td>" . $row['id'] . "</td>";
                echo "<td>" . $row['name'] . "</td>";
                echo "<td>" . $row['email'] . "</td>";
                echo "<td>" . $row['age'] . "</td>";
                echo "</tr>";
            }
        } else {
            echo "<tr><td colspan='4'>No records found.</td></tr>";
        }
        ?>
    </table>
</body>
</html>

<?php
// Close the connection
mysqli_close($conn);
?>
