			LIST		p=18f452
			INCLUDE		<P18F452.INC>
				
	    		UDATA		0x480
MapName			RES		8
			;ENDC

			EXTERN		MapIndex
filter			CODE

;All digits moved into each register are the Hexadecimal conversions of ASCII characters
MapNamee		movlw		0x54		;T
			movwf		0x482
			movlw		0x61		;a
			movwf		0x483		
			movlw		0x6B		;k
			movwf		0x484	
			movlw		0x65		;e
			movwf		0x485
			movlw		0x20		;SPACE
			movwf		0x486
			movlw		0x32		;2
			movwf		0x487
			movlw		0x20		;SPACE
			movwf		0x488
			movlw		0x00		;NULL
			movwf		0x489

getMapChar		movlw		0x07
			cpfsgt		MapIndex, 0
			goto		getChar
			goto		getInvalidChar
			
getInvalidChar		movlw		0xFF
			return
				
getChar			lfsr		FSR0, 0x482
			movf		MapIndex, W
			movf		PLUSW0, W
			return
		
			GLOBAL		MapNamee	
			GLOBAL		getMapChar

			END