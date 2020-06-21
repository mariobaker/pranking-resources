#! /usr/bin/env python
# Line above is used to inform system this is a python script

#===================================================
# Raspberry Pi Sound Board
# 
# Plays a random sound through the headphone jack from a folder whenever 
# a button is pressed. Each button can correspond to a different folder 
# with different sounds.
#
# Connect buttons to their pin on one end and then so they 
# connect to ground (GND) when pressed.

import os, random # Used to get (random) sound effect and play it

from time import sleep # Sleep used to create a break between button presses

import RPi.GPIO as GPIO # Used to interact with the input/output pins
GPIO.setwarnings(False) # Ignore warning for now
GPIO.setmode(GPIO.BOARD) # Use physical pin numbering to refer to pins

#===============================================
# Button Setup
# Set the pins and folders to use
# Set button pins to be an input pin and set initial value to be pulled up (on, 3.3v)

# Pressing the alarm button will play a sound from the alarm folder
alarmButton = 12
alarmFolder = "/home/pi/Desktop/soundboard/alarm/"
GPIO.setup(alarmButton, GPIO.IN, pull_up_down=GPIO.PUD_UP) 

# Setup for beeps
beepButton = 23
beepFolder = "/home/pi/Desktop/soundboard/beep/"
GPIO.setup(beepButton, GPIO.IN, pull_up_down=GPIO.PUD_UP) 

#================================================
# Code
# Runs the show

# Function to play a random file from a folder
def playRandomFile(sourceFolder) :
    # Pick random file from folder
    filename = random.choice(os.listdir(sourceFolder))
    path = os.path.join(sourceFolder, filename) # Get its path
    
    # Prepare a command to play the file using OMX player
    # outputting the file to the headphone jack
    command = "omxplayer -o local " + path 
    
    # Currently the program will wait until the sound is played entirely
    # However if you want to potentially play multiple sounds simultaneously
    # then you need to run the file in the background, this is done by simply
    # adding an ampersand (&) to the end of the command will achieve this.
    
    #command = command + " &" # Make file play in the background
    os.system(command)
    sleep(0.5) # Half a second between successive files being played
    

while True: # Run forever
    # If any button is pressed (goes "LOW"), play a file from its folder
    
    if GPIO.input(alarmButton) == GPIO.LOW:
        #print("Alarm button was pushed!")
        playRandomFile(alarmFolder) # Play file from its folder
        
    if GPIO.input(beepButton) == GPIO.LOW:
        #print("Beep button was pushed!")
        playRandomFile(beepFolder)
        
