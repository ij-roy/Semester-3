----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    20:42:59 09/22/2024 
-- Design Name: 
-- Module Name:    mux_2_to_1 - Behavioral 
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

entity mux_2_to_1 is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           S1 : in  STD_LOGIC;
           Y : out  STD_LOGIC);
end mux_2_to_1;

architecture Behavioral of mux_2_to_1 is

begin
Y<=(A AND NOT(S1)) OR (B AND S1);

end Behavioral;