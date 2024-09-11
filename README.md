# Wavecalc
Calculator for key parameters of wave propagation and capture. This program is created with Qt Creator 14.0.1. To simply use it one can download and isntall WaveCalc_Installer_win.exe. The rest of the files are the source code.

If you've ever studied the theory behind capturing sound or other waves, you've likely encountered terms like near/far field, antenna size, frequency, wavelength, and sampling rate. Each of these concepts is interconnected and can be expressed as functions of the others. For instance, wavelength is inversely proportional to frequency, and the sampling rate is proportional to frequency. Additionally, the boundary between the near and far field depends on both the wavelength and the size of the antenna.
For example, I’m currently working on designing a device that samples sound waves. To ensure accuracy, I need to determine whether my device can sample and process data at least twice the speed of the wave frequency, or whether I should focus on waves for which my device’s speed is sufficient. Therefore, I’m aiming to sample waves with longer wavelengths (λ) and lower frequencies. However, I must also restrict the device’s operation to the near field, which influences the required size of the antenna (D).
In short, I need a tool that can quickly calculate the relationships between these variables, making it easier to identify the optimal parameters for my project. 
The main formula I use is this: Rfarfield=(2D2)/λ .
Where:
Rfarfield is the boundary between the near and far field. 
D- is the largest length of the antenna (for array antennas, it is the greatest distance between two sensors).
λ- frequency of the examined signal. 
The sampling rate is simply double the sound frequency, so I don't include it due to its easy calculation. 
The calculator offers two primary functions. First, by inputting values for D (antenna size) and λ (wavelength), you can calculate R (the near/far field boundary). The second option allows you to fix one of the three parameters, assign a variable value to the second, and calculate the third. This makes it easy to explore the relationships between these variables and identify appropriate parameters for your design.
For example, if you set the frequency slider to 100 Hz, this value will automatically appear in the "Frequency" box. The frequency range extends up to 10,000 Hz, so you can fine-tune your selection by entering a specific frequency directly into the box and pressing Enter (real numbers are accepted).
After adjusting or inputting a frequency, the "Wavelength (λ)" field will automatically update—this works in both directions, so you can directly select either frequency or wavelength. Each time you press Enter or adjust the sliders, the near/far field boundary (R) is recalculated. This feature allows for quick and precise calculations of R based on your desired frequency and wavelength.
In the second mode, you have several menus where you can set the following parameters: 
Fix – the drop-down menu Fixes one of the three parameters. Its purpose is to lock the current value (displayed in the corresponding box). 
Hold – allows you to choose a parameter whose mean value will be taken from the corresponding box, but will be calculated with a given deviation in percentages. For example, a wavelength of 3m with a 10% deviation means the third parameter will be calculated n times, starting with the minimum and ending with the maximum value. 
% - controls the percentage deviation. 
Steps – sets the number of steps for the calculation between the minimum and maximum value of the selected variable. 
The “Calculate” button performs the requested calculations and fills in the table below. 
Example calculation: Given R=3m and Frequency=1000 Hz, we could explore how the size of the antenna (D) changes. I will fix R and give a 50% deviation to the frequency, leaving the default number of steps at 10. Note that when entering the frequency, R will automatically update, so it’s important to input R last. From the completed table, it becomes clear that the wavelength is directly proportional to the size of the antenna. Let’s assume that 0.5m is an appropriate size for our antenna, in which case we understand that we need to study a sound with a wavelength of 0.171500. Quickly copying this value and entering it into Wavelength (λ) shows that we will need to receive a signal with a frequency of 2000 Hz or achieve double that for the sampling frequency. Personally, this worries me, and I would play around with the antenna size and R to achieve lower frequencies, which my device would process faster with fewer samples. 

I hope this calculator will be useful to you. The program is open-source and is officially published at the following address:
address
Feedback, comments, and suggestions are always welcome at pavlovvalkan@gmail.com 
