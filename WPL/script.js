function generateCalendar() {
    // Get user input
    const year = document.getElementById('year').value;
    const month = document.getElementById('month').value - 1; // Month index starts from 0 in JavaScript

    // Validate input
    if (!year || month < 0 || month > 11) {
        alert("Please enter a valid year and month (1-12).");
        return;
    }

    // Get first day and number of days in the month
    const firstDay = new Date(year, month, 1).getDay();
    const totalDays = new Date(year, month + 1, 0).getDate();

    // Create table for calendar
    const days = ['Sun', 'Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat'];
    let table = '<table><tr>';
    days.forEach(day => table += `<th>${day}</th>`);
    table += '</tr><tr>';

    // Add blank cells for days before the start of the month
    for (let i = 0; i < firstDay; i++) {
        table += '<td></td>';
    }

    // Fill in the days of the month
    for (let date = 1; date <= totalDays; date++) {
        if ((firstDay + date - 1) % 7 === 0 && date > 1) {
            table += '</tr><tr>'; // Start a new row
        }
        table += `<td>${date}</td>`;
    }
    table += '</tr></table>';

    // Display the calendar in the calendar div
    document.getElementById('calendar').innerHTML = table;
}
