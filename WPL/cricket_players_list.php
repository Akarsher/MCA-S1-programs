<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Indian Cricket Players</title>
    <style>
        table {
            width: 50%;
            border-collapse: collapse;
            margin: 20px auto;
        }
        th, td {
            border: 1px solid #ddd;
            padding: 8px;
            text-align: center;
        }
        th {
            background-color: #4CAF50;
            color: white;
        }
    </style>
</head>
<body>
    <h2 style="text-align: center;">List of Indian Cricket Players</h2>

    <?php
    $players = array("Sachin Tendulkar", "Virat Kohli", "Rohit Sharma", "MS Dhoni",
    "Rahul Dravid", "Hardik Pandya", "Yuvraj Singh", "Ravindra Jadeja");

    echo "<table>";
    echo "<tr><th>Serial No.</th><th>Player Name</th></tr>";

    foreach ($players as $index => $player) {
        echo "<tr>";
        echo "<td>" . ($index + 1) . "</td>";
        echo "<td>" . $player . "</td>";
        echo "</tr>";
    }

    echo "</table>";
    ?>
</body>
</html>
