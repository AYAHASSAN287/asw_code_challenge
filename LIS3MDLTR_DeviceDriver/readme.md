Notes:

1-the init function shall assign the data from the struct 
"LIS3MDLTR_Configuration" 
to the registers resoinsible for configuration it wasn't part of the requested APIs 
i add it as an example 


2-there should be an API to get the current scale senstivity from the register i didn't impelment it for lack of time and instead i used a global variable assuming the scale to be 4 gauss 