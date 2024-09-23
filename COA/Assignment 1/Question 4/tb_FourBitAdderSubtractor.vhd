--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   18:10:01 09/22/2024
-- Design Name:   
-- Module Name:   /home/ise/Assignment1/tb_FourBitAdderSubtractor.vhd
-- Project Name:  Assignment1
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: FourBitAdderSubtractor
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
 
ENTITY tb_FourBitAdderSubtractor IS
END tb_FourBitAdderSubtractor;
 
ARCHITECTURE behavior OF tb_FourBitAdderSubtractor IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT FourBitAdderSubtractor
    PORT(
         A : IN  std_logic_vector(3 downto 0);
         B : IN  std_logic_vector(3 downto 0);
         Control : IN  std_logic;
         Sum : OUT  std_logic_vector(3 downto 0);
         Cout : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic_vector(3 downto 0) := (others => '0');
   signal B : std_logic_vector(3 downto 0) := (others => '0');
   signal Control : std_logic := '0';

 	--Outputs
   signal Sum : std_logic_vector(3 downto 0);
   signal Cout : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: FourBitAdderSubtractor PORT MAP (
          A => A,
          B => B,
          Control => Control,
          Sum => Sum,
          Cout => Cout
        );


   -- Stimulus process
   stim_proc: process
   begin		
		  -- addition: A = 5, B = 3
        A <= "0101"; 
        B <= "0011"; 
        Control <= '0';  -- Addition
        wait for 10 ns;

		  -- subtraction: A = 5 , B = 3 
        A <= "0101"; 
        B <= "0011"; 
        Control <= '1';  
        wait for 10 ns;   
			
		  -- subtraction with borrow: A = 3 , B = 5 
        A <= "0011"; 
        B <= "0101"; 
        Control <= '1';  
        wait for 10 ns; 
		  
		  -- addition of two maximum values: A = 15 , B = 15 
        A <= "1111"; 
        B <= "1111"; 
        Control <= '0';  
        wait for 10 ns;  
			
		  -- subtraction resulting in zero: A = 7 , B = 7 
        A <= "0111"; 
        B <= "0111"; 
        Control <= '1'; 
        wait for 10 ns;   
		  
      wait;
   end process;

END;