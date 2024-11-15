--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   17:31:19 10/15/2024
-- Design Name:   
-- Module Name:   /home/ise/Assignment3/pipo_tb.vhd
-- Project Name:  Assignment3
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: pipo
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
 
ENTITY pipo_tb IS
END pipo_tb;
 
ARCHITECTURE behavior OF pipo_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT pipo
    PORT(
         clk : IN  std_logic;
         enable : IN  std_logic;
         reset : IN  std_logic;
         data_in : IN  std_logic_vector(3 downto 0);
         data_out : OUT  std_logic_vector(3 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal clk : std_logic := '0';
   signal enable : std_logic := '0';
   signal reset : std_logic := '0';
   signal data_in : std_logic_vector(3 downto 0) := (others => '0');

 	--Outputs
   signal data_out : std_logic_vector(3 downto 0);

 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: pipo PORT MAP (
          clk => clk,
          enable => enable,
          reset => reset,
          data_in => data_in,
          data_out => data_out
        );

   -- Clock process definitions
   clk_process :process
   begin
		while true loop
			clk <= '0';
			wait for 1 ns;
			clk <= '1';
			wait for 1 ns;
			end loop;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
		reset <= '1';
		wait for 200 ns; 
		reset <= '0';
		wait for 200 ns; 
		enable <= '1';
		data_in <= "1010"; 
		wait for 200 ns; 
		data_in <= "1100"; 
		wait for 200 ns; 
		enable <= '0'; 
		wait for 200 ns; 
		reset <= '1';
		wait for 200 ns; 
		reset <= '0';
		wait for 200 ns; 
		enable <= '1';
		data_in <= "0110"; 
		wait for 200 ns; 
      wait;
   end process;

END;