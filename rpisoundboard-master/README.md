# Raspberry Pi Sound Board
Turn any Raspberry Pi into a sound board that will play sounds as you press buttons. Simply connect the buttons properly, load your effects into folder, and then run the python script. The sound will be output to the headphone jack on standard RPi models, outputting audio on an RPi Zero is out of the scope of this but the code can be easily adapted.

Note that the audio output on an RPi isn't super strong so it will need an amplifier for respectable output.

## Set up
There are some steps to take to customise this.

### Selecting and collecting effects
The python script isn't limited to a single effect per button - each input pin configured will play a randomly selected file from a folder specific to it when pressed. If you only want a single effect for a button, only put one file in the folder for that button.

To set up your effects save them in either .mp3 or .ogg format, and sort them into folders. For example, we put all our 'beeps' in one folder, this way when we press our 'beep' button one of the beeps is played from this folder. We made a sperate folder for our 'alarms'. You can make as many of these as there are inputs on the Raspberry Pi header (26).

You can download and sort these on your own computer and use a USB to copy them over to be used. Ensure that your USB is in an acceptable format for both your computer and the RPi. FAT32 is acceptable for any OS.

### Setting up the python script
The python script requires minimal editing to adjust. To add support for additional buttons simply copy existing code for other and adjust it. Remember there are two places that need copying, the setup of each button, and then in the infinite loop to check the button if it got pressed.

To remove buttons simply delete sections related to the buttons no longer needed.

One thing that considerably alters the behaviour of the sound board is whether you want to allow sounds to be run in the 'background' allowing them to be played over one another if buttons are pressed in quick succession. By default, the script will play a sound and will not acknowledge any other input until that effect is done playing. This is explained in more detail in the script and configured in the `playRandomFile` function.

**Be sure to test you script out thoroughly before hiding it away inside a prank so you it acts as you expect it to.**

### Setting up the RPi's boot
With everything set up on the RPi, the script tested, we need to configure the script to run on boot. This way if the RPi loses power temporarily (like when it's moved) and reboots, it will load the script automatically allowing the noise to continue. This isn't too difficult to set up:
1. Set the script to be executable by anyone.
   - When you open the file's properties, its under "Permissions"
2. Copy the location of the script
3. Open the terminal
4. Open `rc.local` for editing. **This script controls things that run on a successful boot.**
   > `sudo nano /etc/rc.local/`
5. Insert a line before `exit 0` to run the script
   > `sudo python <paste script location here> &`
   - The ampersand `&` at the end is required, so the script is run in its own process and doesn't interfere with the rest of booting
   
*Note: an example `rc.local` is included alongside the python script.* 

### Setting up the hardware
Hardware set up is trivial and left as an exercise for the pranker. In all seriousness, each "button" needs to simply short the input pin to ground when interacted with, typically pressed. You can also use levers, a conductive stylus or other things to act as switches/buttons.

Although easy to use, breadboards aren't the best for maintaining constant contact, especially with stranded (non-solid) wires. Try to use jumpers and splice them to wires used for your buttons to connect directly to the RPi. If you're really feeling up to it, you can try to solder the wires to the back of the header on the RPi. Try to ensure constant contact with the wires are your "buttons" as well, hopefully with solder too.
