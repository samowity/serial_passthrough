from usb_cdc import console, data

while True:
    try:
        if (n := data.in_waiting):
            console.write(data.read(n))
        if (n := console.in_waiting):
            data.write(console.read(n))
    except KeyboardInterrupt:
        # multiple Ctrl-C on console serial will break loop!!!
        # send Ctrl-C char
        data.write(b'\x03')
