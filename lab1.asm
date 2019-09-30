			LIST		p=18f452
			INCLUDE		<P18F452.INC>
				
	    		CBLOCK		0x480
			MapName:	8
			ENDC

			EXTERN		MapIndex
filter			CODE

;All digits moved into each register are the Hexadecimal conversions of ASCII characters
MapNamee		movlw		0x3D		;M
			movwf		0x480
			movlw		0x3D		;a
			movwf		0x481		
			movlw		0x3D		;p
			movwf		0x482	
			movlw		0x3D		;N
			movwf		0x483
			movlw		0x3D		;a
			movwf		0x484
			movlw		0x3D		;m
			movwf		0x485
			movlw		0x3D		;e
			movwf		0x486
			movlw		0x00		;NULL
			movwf		0x487

getMapChar		movlw		0x07
			cpfsgt		MapIndex, 0
			goto		getChar
			goto		getInvalidChar
			
getInvalidChar		movlw		0xFF
			return
				
getChar			lfsr		FSR0, 0x480
			movf		MapIndex, W
			movf		PLUSW0, W
			return
		
			GLOBAL		MapNamee	
			GLOBAL		getMapChar

			END
