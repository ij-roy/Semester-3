--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   19:55:19 09/22/2024
-- Design Name:   
-- Module Name:   /home/ise/Assignment2/tb_decoder_3_to_8.vhd
-- Project Name:  Assignment2
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: decoder_3_to_8
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY tb_decoder_3_to_8 IS
END tb_decoder_3_to_8;
 
ARCHITECTURE behavior OF tb_decoder_3_to_8 IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT decoder_3_to_8
    PORT(
         A : IN  std_logic_vector(2 downto 0);
         E : IN  std_logic;
         Y : OUT  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic_vector(2 downto 0) := (others => '0');
   signal E : std_logic := '0';

 	--Outputs
   signal Y : std_logic_vector(7 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: decoder_3_to_8 PORT MAP (
          A => A,
          E => E,
          Y => Y
        );


   -- Stimulus process
   stim_proc: process
   begin		
		A <= "111"; 
		E <= '1';
		WAIT FOR 100 ns;
		A <= "010"; 
		E <= '1';
		WAIT FOR 100 ns;
		A <= "001"; 
		E <= '1';
		WAIT FOR 100 ns;
		
      wait;
   end process;

END;