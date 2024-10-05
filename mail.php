<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $voornaam = htmlspecialchars($_POST['voornaam']);
    $achternaam = htmlspecialchars($_POST['achternaam']);
    $email = htmlspecialchars($_POST['email']);
    $telefoonnumer = htmlspecialchars($_POST['telefoonnumer']);
    $bericht = htmlspecialchars($_POST['bericht']);

    if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        echo "Invalid email format";
        exit;
    }

    $to = "akashsewdajal@hotmail.com"; // Vervang dit met je eigen e-mailadres
    $subject = "Mail vanuit toonparket.nl";
    $body = "Name: $voornaam $achternaam\nEmail: $email\nTelefoonnumer: $telefoonnumer\nMessage:\n$bericht";
    $headers = "From: $email";

    if (mail($to, $subject, $body, $headers)) {
        echo "Message sent successfully!";
    } else {
        echo "Failed to send message.";
    }
}
?>