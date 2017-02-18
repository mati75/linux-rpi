#!/usr/bin/php
<?php
  $fhr = fopen('debian/patches/series','r');
  $fhp = fopen('debian/patches/series.prefix','w');
  $fhs = fopen('debian/patches/series.suffix','w');

  $foundpipatch = false;
  while (!feof($fhr)) {
    $line = fgets($fhr);
    if (substr($line,0,8) == 'rpi/rpi_') {
      $foundpipatch = true;
    } else if (!$foundpipatch) {
      fwrite($fhp,$line);
    } else {
      fwrite($fhs,$line);
    }
  }
  fclose($fhr);
  fclose($fhp);
  fclose($fhs);
  
?>