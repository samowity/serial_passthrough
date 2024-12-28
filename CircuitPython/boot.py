import usb_cdc
import supervisor
import storage
import board, digitalio

supervisor.runtime.autoreload = False

usb_cdc.enable(console=True, data=True)    # Enable console and data

button = digitalio.DigitalInOut(board.D10)
button.pull = digitalio.Pull.UP

if button.value:
   storage.disable_usb_drive()
else:
    # change drive label: CIRCUITPY -> PASSTHROUGH
    storage.remount("/", readonly=False)
    m = storage.getmount("/")
    m.label = "PASSTHROUGH"
    storage.remount("/", readonly=True)
    storage.enable_usb_drive()
