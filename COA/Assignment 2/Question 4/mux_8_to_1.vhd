----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    20:26:12 09/22/2024 
-- Design Name: 
-- Module Name:    mux_8_to_1 - Behavioral 
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

entity mux_8_to_1 is
	Port ( A : in  STD_LOGIC_VECTOR (7 downto 0);
			S1,S2,S3: IN STD_LOGIC;
           Y : out  STD_LOGIC);
end mux_8_to_1;

architecture Behavioral of mux_8_to_1 is

begin
Y<=((NOT (S1) AND NOT(S2) AND NOT (S3) AND A(0)) OR (NOT (S1) AND NOT (S2) AND S3 AND A(1)) OR (NOT(S1) AND S2 AND NOT(S3) AND A(2)) OR (NOT (S1) AND S2 AND S3 AND A(3)) OR (S1 AND NOT(S2) AND NOT(S2) AND A(4)) OR (S1 AND NOT (S2) AND S3 AND A(5)) OR (S1 AND S2 AND NOT(S3) AND A(6)) OR(S1 AND S2 AND S3 AND A(7)));

end Behavioral;