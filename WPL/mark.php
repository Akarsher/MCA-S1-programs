<?php

$conn = mysqli_connect("localhost", "root", "", "muthoot");
if (!$conn) {
  die("Connection failed: " . mysqli_connect_error());
}

echo "Connected successfully.<br>";

$sql = "SELECT * FROM mark";
$res = mysqli_query($conn, $sql);
$totrows = mysqli_num_rows($res);

if ($totrows == 0) {
  echo "No records found.";
} else {
  echo "<div class='student-box'>";
  echo "Mark of Students :";
  echo "<style>
  table, th, td {
    border:1px solid black;
  }
  </style>";
  echo "<table style='width:50%'>
          <tr>
            <th>Rollno</th>
            <th>SE Marks</th>
            <th>DS Marks</th>
            <th>DF Marks</th>
          </tr>";

  while ($rows = mysqli_fetch_assoc($res)) {
    echo "<tr>
            <td>" . $rows["rollno"] . "</td>
            <td>" . $rows["ase_marks"] . "</td>
            <td>" . $rows["ads_marks"] . "</td>
            <td>" . $rows["df_marks"] . "</td>
          </tr>";
  }

  echo "</table>";
  echo "</div>";
}

mysqli_close($conn);
?>
