----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    20:00:13 09/22/2024 
-- Design Name: 
-- Module Name:    decoder_4_to_16 - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity decoder_4_to_16 is
	Port (
        A : IN STD_LOGIC_VECTOR (3 DOWNTO 0); 
		  E : in std_logic;
        Y : OUT STD_LOGIC_VECTOR (15 DOWNTO 0)
		);
end decoder_4_to_16;

architecture Behavioral of decoder_4_to_16 is
	COMPONENT decoder_3_to_8 IS
        Port (
            A : IN  STD_LOGIC_VECTOR (2 DOWNTO 0);
            E : IN  STD_LOGIC;
            Y : OUT STD_LOGIC_VECTOR (7 DOWNTO 0)
        );
			  END COMPONENT;
			  component decoder_1_to_2 is
			  Port ( Y : in  STD_LOGIC;
           E : in  STD_LOGIC;
           Y1 : out  STD_LOGIC;
           Y2 : out  STD_LOGIC);
			  end component;
	signal t1,t2: STD_LOGIC;

begin
	step1:decoder_1_to_2 port map(A(0),E,t1,t2);
	L1: decoder_3_to_8 PORT MAP (
        A=> A(2 downto 0),   
        E => t1,            
        Y(0) => Y(0),
        Y(1) => Y(1),
        Y(2) => Y(2),
        Y(3) => Y(3),
        Y(4) => Y(4),
        Y(5) => Y(5),
        Y(6) => Y(6),
        Y(7) => Y(7)   
		);
	L2: decoder_3_to_8 PORT MAP (
        A => A(2 DOWNTO 0),  
        E => t2,          
         Y(0) => Y(8),
        Y(1) => Y(9),
        Y(2) => Y(10),
        Y(3) => Y(11),
        Y(4) => Y(12),
        Y(5) => Y(13),
        Y(6) => Y(14),
        Y(7) => Y(15)   
    );

end Behavioral;