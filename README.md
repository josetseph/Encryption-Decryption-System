# Encryption-Decryption-System
Took 3 hours to complete this. 
You can use this to encrypt any message. 
The decryption system is also within the same program.

You cannot use spaces in this program though.
So instead of Hello there beautiful lady, it'll be HelloThereBeautifulLady.

The fault comes from the decryption system.
It works on the basis of groups of four but spacebar encrypted becomes BF3 and it messes with the decryption system.
Best not use space when encrypting your message so you can easily decrypt later.

The encryption system converts to ascii, runsa a few math operations, then converts to hex and prints the hex version in reverse.
ie: 
H - 143B
E - 1294
L - 168B
L - 168B
O - 185C
But the final (after reversal) is HELLO - B3414921B861B861C581
The decryption system reverses that process, obviously.

Decryption is actually harder than encryption... yeesh!
