----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    19:49:45 09/22/2024 
-- Design Name: 
-- Module Name:    decoder_3_to_8 - Behavioral 
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

entity decoder_3_to_8 is
    Port (   A : in  STD_LOGIC_VECTOR (2 DOWNTO 0);
            E : in  STD_LOGIC;
            Y : out STD_LOGIC_VECTOR (7 DOWNTO 0));
end decoder_3_to_8;

architecture Behavioral of decoder_3_to_8 is

begin
	Y(0) <= (NOT A(0)) AND (NOT A(1)) AND (NOT A(2)) AND E;
	Y(1) <= (NOT A(0)) AND (NOT A(1)) AND A(2) AND E;
	Y(2) <= (NOT A(0)) AND A(1) AND (NOT A(2)) AND E;
	Y(3) <= (NOT A(0)) AND A(1) AND A(2) AND E;
	Y(4) <= A(0) AND (NOT A(1)) AND (NOT A(2)) AND E;
	Y(5) <= A(0) AND (NOT A(1)) AND A(2) AND E;
	Y(6) <= A(0) AND A(1) AND (NOT A(2)) AND E;
	Y(7) <= A(0) AND A(1) AND A(2) AND E;
end Behavioral;