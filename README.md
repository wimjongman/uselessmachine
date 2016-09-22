# uselessmachine
Welcome to our [reverse engineered useless machine](https://www.instagram.com/p/BKUMYfXB-oK). We designed the machine in *123d*, printed it on our *ZMorph 2.0 S* programmed the software on an *Arduino mini pro* with the *Sloeber IDE*.

## Parts needed
* Two [SG90 Servos](https://google.com/search?q=sg90+servo)
* One [Arduino Pro Mini](https://google.com/search?q=arduine+pro+mini) or equivalent
* One [3D Printer](https://store.zmorph3d.com) with some [filament](https://www.google.nl/search?q=filament)
* A [toggle or flip switch](https://google.com/search?q=toggle+switch) that toggles easy
* A bunch of male/male male/female female/female [breadbord cables](https://google.com/search?q=breadboard+cables).
* Glue, preferably a [Hot Glue Gun](https://google.com/search?q=hot+glue+gun)
* Solder and soldering iron

## Glueing. Warning.
Make sure everyting is aligned and measured before starting to glue.

## Printing
* Print [the box](https://github.com/wimjongman/uselessmachine/blob/master/123d/case.stl). 
* Print the [flip lid](https://github.com/wimjongman/uselessmachine/blob/master/123d/fliplid.stl). Print it directly on the glass for a smooth surface.
* Print the [hinge pin](https://github.com/wimjongman/uselessmachine/blob/master/123d/hingepin.stl) and finish it with a bit of sandpaper until it is smooth.
* Print the [lid containing the flip switch](https://github.com/wimjongman/uselessmachine/blob/master/123d/switchlid.stl). The rising edge connects to the front of the box.
* Print the [holder for the lid flip engine](https://github.com/wimjongman/uselessmachine/blob/master/123d/fliplidengineholder.stl). Eventually glue a servo into this holder and glue the holder in the back left corner of the case. 
* Print the [flip switch shaft](https://github.com/wimjongman/uselessmachine/blob/master/123d/flipswitchengineshaft.stl). Eventually, glue the [servos two arm horn](https://github.com/wimjongman/uselessmachine/blob/master/123d/SG90-2-arms-horn.stl) into the shaft (don't print the horn. It comes with the servo). Make sure to not fill the center hole of the horn with glue. It needs to be mounted on the servos axis.
* Print the [flip switcher engine holder](https://github.com/wimjongman/uselessmachine/blob/master/123d/flipswitchengineholder.stl). Eventually glue a servo into this holder and glue the holder in the front of the case such that the flip switch alings with the center of the shaft. 
* Print the [flip switch arm](https://github.com/wimjongman/uselessmachine/blob/master/123d/fliparm2.stl). I'm pretty sure it was this one, otherwise try [one of these](https://github.com/wimjongman/uselessmachine/blob/master/123d/fliparm.stl). The arms slide over the shaft and lock into place. Nudge it to as far as it can go.

## Glueing. Warning 2.
Make sure everyting is aligned and measured before starting to glue.

## Programming the Arduino
Download [Sloeber](http://sloeber.io), unzip and untar it with 7zip and place it in a convenient location. Then

* Run it; 
* Wait until the additional software is downloaded;
* Open the git perspective and clone this repo;
* Import the com.weltevree.uselessmachine project;
* Flash the code. You might want to use another [Arduino to program the mini](https://www.arduino.cc/en/Tutorial/ArduinoISP)




