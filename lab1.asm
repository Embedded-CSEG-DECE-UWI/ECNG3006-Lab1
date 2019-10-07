
	LIST p=18F452
	
			INCLUDE<p18f452.INC>
			GLOBAL MapName0
			GLOBAL getMapChar
			
MapName0  EQU   0x31
MapName1  EQU   0x32
MapName2  EQU   0x33
MapName3  EQU   0x34
MapName4  EQU   0x35
MapName5  EQU   0x36
MapName6  EQU   0x37
MapName7  EQU   0x38
			
			
			extern    MapIndex
			
			ORG 0x00
			goto	main
			ORG		0x10
	
main			goto getMapChar

getMapChar		movf 	b'0111',w
			subwf	MapIndex
			btfsc   STATUS,Z
			goto 	equal
			btfsc   STATUS,C
			goto	MapIndexGreater
			movf    MapName0,w
			return
equal			nop;
			
MapIndexGreater		movf b'11111111',w
				return
			

    END 
    