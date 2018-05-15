# Lab 11

The code for this lab is based on an introductory example in [Starting
out with C++][1]. It includes a base class, `Automobile`, and three
derived classes, `Car`, `Truck`, and `SUV`.

Complete the following:

1. Derive two new classes from `Car`:
 * `SportsCar`, with a new member variable `topSpeed`
 * `ElectricCar`, with a new member variable `maximumRange`

2. Override the `describe` method for each subclass to include the
   new information.

3. Create a `SportsCar` and an `ElectricCar` and add them to the
   dealership's `stock`.

4. Verify that `list_inventory()` shows the new cars and their
   descriptions correctly.

5. Add a new member function, `testDrive()`, which takes a parameter
   `length` and adds it to the current `mileage`.

6. Take each car for a test drive, then list the inventory again to
   verify that the mileage has been updated.


[1]: https://www.pearson.com/us/higher-education/product/Gaddis-Starting-Out-with-C-from-Control-Structures-to-Objects-8th-Edition/9780133769395.html
