<?php
// Database connection
$conn = mysqli_connect("localhost", "root", "", "muthoot");
if (!$conn) {
    die("Not connected: " . mysqli_connect_error());
}

// Handle form submission
if (isset($_POST['submit'])) { // Use isset to check if the submit button was clicked
    $name = $_POST["name"];
    $age = $_POST["age"];
    $course = $_POST["course"];
    
    if (!empty($name) && is_numeric($age) && !empty($course)) {
        $insert = "INSERT INTO student(name, age, course) VALUES ('$name', $age, '$course')";
        mysqli_query($conn, $insert);
    } else {
        echo "<p style='color:red;'>Values entered are not valid!</p>";
    }
}

// Retrieve data from the database
$sql = "SELECT * FROM student";
$res = mysqli_query($conn, $sql);
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Student Form</title>
    <script>
        function validateForm() {
            var name = document.getElementById("name").value;
            var age = document.getElementById("age").value;
            var course = document.getElementById("course").value;
            
            if (name == "" || course == "") {
                alert("Name and Course must be filled out");
                return false;
            }
            
            if (isNaN(age) || age <= 0) {
                alert("Please enter a valid positive age");
                return false;
            }
        }
    </script>
</head>
<body>
    <h2>Student Details:</h2>
    <form method="POST" onsubmit="return validateForm()">
        NAME: <input id="name" name="name" type="text"><br><br>
        AGE: <input id="age" name="age" type="number"><br><br>
        COURSE: <input id="course" name="course" type="text"><br><br>
        <button name="submit" type="submit">Submit</button>
    </form>

    <h3>Student List:</h3>
    <table border="1" cellpadding="5" cellspacing="0">
        <tr>
            <th>Name</th>
            <th>Age</th>
            <th>Course</th>
        </tr>
        <?php
        if (mysqli_num_rows($res) > 0) {
            while ($rows = mysqli_fetch_assoc($res)) {
                echo "<tr>";
                echo "<td>" . $rows["name"] . "</td>";
                echo "<td>" . $rows["age"] . "</td>";
                echo "<td>" . $rows["course"] . "</td>";
                echo "</tr>";
            }
        }
        ?>
    </table>
</body>
</html>
