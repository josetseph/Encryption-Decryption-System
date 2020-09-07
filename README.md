# Encryption-Decryption-System
To encrypt any text-based message.

You can use this to encrypt any text based message. 
The decryption system is also within the same program.

The encryption system converts to ascii, runs a a few math operations, then converts to hex and prints the hex version in reverse.
ie: 
H - 143B
E - 1294
L - 168B
L - 168B
O - 185C
But the final (after reversal) is HELLO - B3414921B861B861C581
The decryption system reverses that process, obviously.

Decryption is actually harder than encryption... yeesh!

Update:
Finally included the implementation of key systems which are needed in order to decipher the message.
The person encrypting the message must send the encrypted message along with the keys that are generated else the encoded message cannot be decrpted successfully.

Does not include numbers and symbols. Only letters and spaces. Adding Numbers and Symbols will bug out the program.
Might update to a version that accepts numbers and letters as well... maybe now, maybe never.
