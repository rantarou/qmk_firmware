Rantarou 60 Handwired
======================

This firmware is for Rantarou60 handwired with an Arduino Micro.
NOTE: The Arduino Micro is different than the Arduino *Pro* Micro.

## Wiring Layout

TBA

## Material Checklist
- Wooden Sandwich Case
- 1N4148 Diode
- 330ohm Resistor
- Ice Blue Square LED
- Cherry MX Compatible switches

## Pinout

The following pins are used:
- Columns 1-14: B2, B0, D3, D2, D1, D0, D4, C6, D7, E6, B4, B5, B6, D6
- Rows 1-5: F0, F1, F4, F5, F6
- Led: B7

## Compiling and loading the firmware

To build the firmware, run `make`.

To flash the firemware onto the microcontroller, run `make avrdude`, and press the reset button.
